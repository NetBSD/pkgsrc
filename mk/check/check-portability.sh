# $NetBSD: check-portability.sh,v 1.22 2020/05/05 05:55:26 rillig Exp $
#
# This program checks all files in the current directory and any
# subdirectories for portability issues that are likely to result in
# false assumptions by the package.
#
# The most prominent example is the "==" operator of test(1), which is
# only implemented by bash and some versions of the ksh.
#
# usage: cd $WRKSRC && [SKIP_FILTER=...] check-portability.sh
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

	if test -f "${PREFIX}/bin/check-portability"; then
		${PREFIX}/bin/check-portability "$1" 1>&2 \
		|| cs_exitcode=1
	fi
}

patched_files=",$(awk '
	BEGIN {
		if (ARGV[1] ~ /\/patch-\*$/)
			exit;
		ORS = ","
	}
	/^\+\+\+ / {
		print $2
	}' \
	"$PATCHDIR"/patch-*),"

find ./* -type f -print 2>/dev/null \
| sed 's,$,_,' \
| {
	opsys=`uname -s`-`uname -r`
	while read fname; do
		fname="${fname#./}"
		fname="${fname%_}"

		skip=no
		eval "case \"\$fname\" in $SKIP_FILTER *.orig) skip=yes;; esac"
		case "$fname" in *.in)
			case ",$patched_files," in *,"${fname%.in}",*)
				skip=yes
			esac
		esac
		[ $skip = no ] || continue

		skip_shebang_test=no
		base="${fname##*/}"
		ext="${base##*.}"
		case "$ext" in
		# A few file extensions cannot be skipped since the Makefiles
		# will be generated from these, in the configure stage, which
		# is run later.
		(in|mk|Makefile|makefile|GNUmakefile) skip_shebang_test=yes;;

		# echo */*/PLIST | xargs cat | sed s,'.*\.',, | sort | uniq -c | sort -nr | sed 40q
		(png|html|svg|py|h|mo|php|js|xml|rb|go|txt|3|hpp)	continue ;;
		(tfm|gif|dtd|properties|json|ogg|gz|test|result|xpm|po)	continue ;;
		(page|1|kicad_mod|hxx|jpg|css|el|htm|a|docbook|vf|inc)	continue ;;

		# other source files:
		(c|C|cc|cxx|f|go|pl|py|ac|m4)				continue ;;
		esac

		if [ "$CHECK_PORTABILITY_EXPERIMENTAL" = yes ] &&
		   [ $skip_shebang_test = yes ]; then
			check_shell "$fname"
			continue
		fi

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
