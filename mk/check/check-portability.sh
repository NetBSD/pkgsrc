# $NetBSD: check-portability.sh,v 1.3 2006/11/09 14:36:18 rillig Exp $
#
# This program checks the extracted files for portability issues that
# are likely to result in false assumptions by the package.
#
# The most prominent example is the "==" operator of test(1), which is
# only implemented by bash and some versions of the ksh.
#

set -eu

. "${PKGSRCDIR}/mk/check/check-subr.sh"
cs_setprogname "$0"

found_random=no
found_test_eqeq=no

# usage: check_shell <fname>
check_shell() {
	env \
		CK_FNAME="$1" \
		CK_PROGNAME="check-portability.awk" \
		awk	-f "$PKGSRCDIR/mk/check/check-subr.awk" \
			-f "$PKGSRCDIR/mk/check/check-portability.awk" \
		< "$1" \
	|| cs_exitcode=1
}

find * -type f -print 2>/dev/null \
| {
	while read fname; do

		skip=no
		eval "case \"\$fname\" in $SKIP_FILTER *.orig) skip=yes;; esac"
		[ $skip = no ] || continue

		read firstline < "$fname" || continue
		case "$firstline" in
		"#!"*"/bin/sh")
			check_shell "$fname"
			;;
		esac
	done

	cs_exit
}
