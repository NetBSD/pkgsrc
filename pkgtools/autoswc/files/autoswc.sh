#!@SH@
#
# $NetBSD: autoswc.sh,v 1.3 2008/10/11 18:03:58 jmmv Exp $
#
# autoswc - Generates system wide cache files for GNU autoconf
# Copyright (c) 2004 Julio M. Merino Vidal <jmmv@NetBSD.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name of author nor the names of its contributors may
#    be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

ProgName=${0##*/}

err() {
    echo "${ProgName}: $*" 1>&2
    exit 1
}

info() {
    echo "${ProgName}: $*" 1>&2
}

mktempdir() {
    local d tmpdir

    # Check if mktemp exists in the current system.
    for d in $(echo ${PATH} | tr ':' ' '); do
        if [ -x $d/mktemp ]; then
            $d/mktemp -d /tmp/autoswc.XXXX
            return
        fi
    done

    # Emulate mktemp; this is not safe.
    info "mktemp(1) not found; race conditions may appear"
    tmpdir=/tmp/autoswc.$$
    mkdir -p ${tmpdir}
    chmod 700 ${tmpdir}
    echo ${tmpdir}
}

usage() {
    echo "Usage: ${ProgName} [-c ac_file] [-n cache_name]" 1>&2
    exit 1
}

# -------------------------------------------------------------------------

# Main program

cachename="default"

confsrc="@PREFIX@/share/autoswc/configure.ac"
[ -f "@SYSCONFDIR@/configure.ac" ] && confsrc="@SYSCONFDIR@/configure.ac"

# Parse command line options
args=$(getopt c:n: $*)
[ $? -ne 0 ] && usage
set -- ${args}
while [ $# -gt 0 ]; do
    case "$1" in
        -c)
            confsrc="$2"; shift
            ;;
        -n)
            cachename="$2"; shift
            ;;
        --)
            shift; break
            ;;
    esac
    shift
done
[ $# -gt 0 ] && usage

# Set the cache name.
confcache="@CACHEDIR@/config.cache.${cachename}"

# Check if we will be able to store the resulting cache file.
# The permissions may change during the execution of this script, but this
# won't bring us problems.  This check is just done to save some time in
# case we got the wrong user running autoswc.
touch ${confcache} >/dev/null 2>&1 || err "can't update ${confcache}"

# Ensure that the source configure.ac exists.
[ ! -f ${confsrc} ] && err "${confsrc} does not exist"

# Create work directory.
wrkdir=$(mktempdir)
info "using ${wrkdir} as work directory"
cd ${wrkdir}

# Create work project.  This includes:
# - Makefile.am - empty, just needs to be present.
# - configure.ac - the user-defined configure.ac file, modified to include
#                  basic and required macros.
# - NEWS README AUTHORS ChangeLog - empty, just need to be present.
echo "# empty" >Makefile.am

echo "AC_INIT(configure.ac, 1)" >configure.ac
echo "AM_INIT_AUTOMAKE" >>configure.ac
cat ${confsrc} >>configure.ac
echo "AC_CACHE_SAVE" >>configure.ac
echo "AC_OUTPUT(Makefile)" >>configure.ac

touch NEWS README AUTHORS ChangeLog

# Generate scripts and add missing files.
info "running @ACLOCAL@..."
@ACLOCAL@
if grep LIBTOOL configure.ac >/dev/null 2>&1; then
    info "running @LIBTOOLIZE@..."
    @LIBTOOLIZE@ --force
fi
info "running @AUTOMAKE@..."
@AUTOMAKE@ --add-missing --force-missing
info "running @AUTOCONF@..."
@AUTOCONF@

# Run the configure script.
[ ! -f configure ] && err "autoconf failed"
CONFIG_SITE= ./configure --cache-file=config.cache \
    --build=@MACHINE_GNU_PLATFORM@ --host=@MACHINE_GNU_PLATFORM@ || \
    err "configure failed"
mv config.cache config.cache.in

# Prune the cache file from entries that will abort configure scripts when
# running from within pkgsrc.  This is not 100% safe, because configure is
# right in warning from changed values, but is needed to get this working.
grep -v "^ac_cv_env" <config.cache.in >config.cache

# Update the cache file.  We don't give it write permissions since we don't
# want third-party configure scripts update it with unwanted results.
install -c -m 444 config.cache ${confcache} || err "can't update ${confcache}"

cd -

rm -rf ${wrkdir}

# Start of summary.
cat <<EOF

===========================================================================
AUTOSWC - SUMMARY FOR \`${cachename}' CACHE

    ${confcache} updated successfully.

EOF

# Warn the user if autoswc.mk is not included from mk.conf.
if ! egrep '^.-?[ \t]*s?include[ \t]+"@PREFIX@/share/autoswc/autoswc.mk"' \
    @MKCONF@ >/dev/null 2>&1; then
    cat <<EOF
    The @MKCONF@ file seems to not include autoswc.mk.  This means that
    configure scripts will not find the generated cache file.  Add the
    following line to it:

    .sinclude "@PREFIX@/share/autoswc/autoswc.mk"

EOF
fi

# Tell the user to define AUTOSWC_CACHE_NAME if he used a custom cache
# name.
if [ ${cachename} != default ]; then
    cat <<EOF
    You have used a non-standard cache name.  To let configure scripts
    find it, you should add the following line somewhere in your
    @MKCONF@ file, in case it is not there yet:

    AUTOSWC_CACHE_NAME= ${cachename}

EOF
fi

# Warn the user about the dangers of using a system wide cache file.
cat <<EOF
    Please remember that by using a system wide cache file, you assume
    that the results stored in it may get outdated and cause strange build
    failures in third-party packages.  When reporting bugs, be absolutely
    sure it is not your fault.  Check the autoswc(8) manpage for more
    details.
===========================================================================
EOF

exit 0

# vim: syntax=sh:expandtab:shiftwidth=4:softtabstop=4
