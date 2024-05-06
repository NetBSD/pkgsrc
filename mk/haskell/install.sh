# $NetBSD: install.sh,v 1.1 2024/05/06 09:33:22 pho Exp $
#
# Install a Cabal package.
#
set -eu

: ${CAT:=cat}
: ${ECHO:=echo}
: ${EXPR:=expr}
: ${FIND:=find}
: ${INSTALL_DATA:=install -m 644}
: ${INSTALL_DATA_DIR:=install -d -m 755}
: ${RMDIR:=rmdir}
: ${SORT:=sort}
: ${TAIL:=tail}
: ${TEST:=test}
: ${TRUE:=true}
: ${XARGS:=xargs}

usage() {
    ${ECHO} >&2 "Usage: $0 -s SRCDIR -d DESTDIR -D PKG_DESCR_FILE_OR_DIR -i PKG_ID_FILE -p PREFIX [-v]"
}

srcdir=
destdir=
pkg_descr_file_or_dir=
pkg_id_file=
prefix=
verbose=
while getopts s:d:D:i:p:v opt; do
    case $opt in
        s)
            srcdir="${OPTARG}";;
        d)
            destdir="${OPTARG}";;
        D)
            pkg_descr_file_or_dir="${OPTARG}";;
        i)
            pkg_id_file="${OPTARG}";;
        p)
            prefix="${OPTARG}";;
        v)
            verbose=1;;
        \?)
            usage
            exit 1
    esac
done
if ${TEST} -z "$srcdir" -o -z "$destdir" -o \
           -z "$pkg_descr_file_or_dir" -o -z "$pkg_id_file" -o \
           -z "$prefix"; then
    usage
    exit 1
fi

cd "$srcdir"

# Never use -v even if verbose output is requested. It writes garbage to
# stdout and messes up the ID file.
./Setup register \
        --gen-pkg-config=dist/package-description \
        --print-ipid \
        > dist/package-id

./Setup copy ${verbose:+-v} --destdir="$destdir"

# Packages may contain internal libraries. If that's the case "./Setup
# register --gen-pkg-config" creates a directory containing files named
# {index}-{pkg-id} for each library. Otherwise it creates a single regular
# file. "./Setup register --print-ipid" becomes useless in this case, as it
# only prints the ID of the main library. devel/hs-attoparsec is an example
# of such packages.
if ${TEST} -d dist/package-description; then
    ${INSTALL_DATA_DIR} "${destdir}${pkg_descr_file_or_dir}"
    ${CAT} /dev/null > dist/package-id
    ${FIND} dist/package-description -type f | ${SORT} |
        while read fpath; do
            # But the thing is, when the package has 10 components or more,
            # "./Setup register" pads the component index with zero! It's
            # nice for human beings but isn't nice for POSIX sh...
            fname="${fpath##*/}"               # "01-foo-bar-1.2.3.4-xxxxxxxx"
            padded_idx="${fname%%-*}"          # "01"
            pkg_id="${fname#*-}"               # "foo-bar-1.2.3.4-xxxxxxxx"
            idx="$(${EXPR} "$padded_idx" + 0)" # "1"
            ${INSTALL_DATA} "$fpath" "${destdir}${pkg_descr_file_or_dir}/${idx}"
            ${ECHO} "$pkg_id" >> dist/package-id
        done
    ${INSTALL_DATA} dist/package-id "${destdir}${pkg_id_file}"

elif ${TEST} -f dist/package-description; then
    ${INSTALL_DATA} dist/package-description "${destdir}${pkg_descr_file_or_dir}"
    ${INSTALL_DATA} dist/package-id          "${destdir}${pkg_id_file}"
fi

# Executable-only packages tend to create an empty directory tree in lib/
# which results in useless @pkgdir in PLIST.
${FIND} "${destdir}${prefix}/lib" -type d |
    ${TAIL} -n 1 |
    ${XARGS} ${RMDIR} -p 2>/dev/null || ${TRUE}
