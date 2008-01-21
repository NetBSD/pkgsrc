# $NetBSD: check-headers.sh,v 1.10 2008/01/21 06:11:09 rillig Exp $
#
# This program checks the header files for possible problems.
#
# When a macro definition contains the characters "${", it is likely
# that is comes from a GNU-style configure script that didn't use the
# ${prefix} or ${exec_prefix} variable correctly.
#

set -eu

checkdir=`dirname "$0"`
. "$checkdir/check-subr.sh"
cs_setprogname "$0"

found_unresolved_variable=no

# usage: check_header <fname>
check_header() {
	# See the end of the loop for the redirection.
	while read line; do

		# Check for "${" in macro definitions.
		case "$line" in
		"#"*define*[\":]\$\{[A-Za-z]*\}/*\"*)
			found_unresolved_variable=yes
			cs_error_heading "Found unresolved variable in macro:"
			cs_error_msg "$fname: $line"
			;;
		esac

	done < "$1"
}

find * -type f -print 2>/dev/null \
| {
	while read fname; do

		skip=no
		eval "case \"\$fname\" in $SKIP_FILTER *.orig) skip=yes;; esac"
		[ $skip = no ] || continue

		case "$fname" in
		*.h | *.hpp | *.h++ | *.hxx)
			check_header "$fname"
			;;
		esac
	done

	if [ $found_unresolved_variable = yes ]; then
		cs_explain <<EOF
The above macros may contain references to shell variables.

The cause of this problem is usually that in a configure.ac or
configure.in file, there is some code like

    FOO_DIR="\${bindir}"
    # ...
    AC_DEFINE_UNQUOTED(FOO_DIR, "\$FOO_DIR", [Directory where foo files go])

You can fix this by telling the original package author not to use
AC_DEFINE_UNQUOTED for directories. Instead, {he,she} should do
something like this:

    # in configure.ac:
    foodir="\${bindir}"
    AC_SUBST(FOO_DIR)

    # in the Makefile.am files (can be more than one):
    AM_CPPFLAGS= -DFOO_DIR=\\"@FOO_DIR@\\"

See also:
http://www.gnu.org/software/autoconf/manual/html_node/Defining-Directories.html

If this check is wrong and the package really wants to have "\${" in the
macros, append the above filenames to the CHECK_HEADERS_SKIP variable in
the package Makefile.
EOF

	fi
	cs_exit
}
