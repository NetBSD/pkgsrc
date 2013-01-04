# $NetBSD: check-portability.sh,v 1.9 2013/01/04 10:51:57 jperkin Exp $
#
# This program checks all files in the current directory and any
# subdirectories for portability issues that are likely to result in
# false assumptions by the package.
#
# The most prominent example is the "==" operator of test(1), which is
# only implemented by bash and some versions of the ksh.
#
# usage: check-portability.sh
#

set -eu

checkdir=`dirname "$0"`
. "$checkdir/check-subr.sh"
cs_setprogname "$0"

: ${SKIP_FILTER:=""}

# usage: check_shell <fname>
check_shell() {
	env \
		CK_FNAME="$1" \
		CK_PROGNAME="check-portability.awk" \
		awk	-f "$checkdir/check-subr.awk" \
			-f "$checkdir/check-portability.awk" \
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
			case "$opsys" in
			SunOS-5.[0-9]|SunOS-5.10)
				echo "WARNING: [check-portability.sh] $fname has /bin/sh as interpreter, which is horribly broken on Solaris." 1>&2
				;;
			esac
			;;
		esac
	done

	cs_exit
}
