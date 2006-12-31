# $NetBSD: check-portability.sh,v 1.5 2006/12/31 13:35:10 rillig Exp $
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
		< "$1" 1>&2 \
	|| cs_exitcode=1
}

find * -type f -print 2>/dev/null \
| {
	opsys=`uname -s`-`uname -r`
	while read fname; do

		skip=no
		eval "case \"\$fname\" in $SKIP_FILTER *.orig) skip=yes;; esac"
		[ $skip = no ] || continue

		case "$opsys" in
		SunOS-5.9)
			# See also (if you can):
			# http://sunsolve.sun.com/search/document.do?assetkey=1-1-4250902-1
			firstline=`sed 1q < "$fname"`
			;;

		*)	read firstline < "$fname" || continue
			;;
		esac

		case "$firstline" in
		"#!"*"/bin/sh")
			check_shell "$fname"
			;;
		esac
	done

	cs_exit
}
