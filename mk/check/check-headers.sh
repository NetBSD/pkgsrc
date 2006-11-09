# $NetBSD: check-headers.sh,v 1.1 2006/11/09 02:53:15 rillig Exp $
#
# This program checks the header files for possible problems.
#
# When a macro definition contains the characters "${", it is likely
# that is comes from a GNU-style configure script that didn't use the
# ${prefix} or ${exec_prefix} variable correctly.
#

set -eu

. "${PKGSRCDIR}/mk/check/check-subr.sh"
cs_setprogname "$0"

# usage: check_header <fname>
check_header() {
	# See the end of the loop for the redirection.
	while read line; do

		# Check for "${" in macro definitions.
		case "$line" in
		"#define"*"\${"*)
			cs_error_heading "Found unresolved variable in macro:"
			cs_error_msg "$fname: $line"
			;;
		esac

	done < "$1"
}

find * -type f -print 2>/dev/null \
| {
	while read fname; do

		case "$fname" in
		*.h | *.hpp | *.h++ | *.hxx)
			;;
		*)
			continue
			;;
		esac

		eval "case \"\$fname\" in $SKIP_FILTER *.orig) continue;; esac"

		check_header "$fname"
	done
	cs_exit
}
