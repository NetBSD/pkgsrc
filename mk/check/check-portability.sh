# $NetBSD: check-portability.sh,v 1.1 2006/11/09 02:53:15 rillig Exp $
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

# usage: check_shell <fname>
check_shell() {
	# See the end of the loop for the redirection.
	while read line; do

		# Note: This code does not find _all_ instances of
		# unportable code. If a single line contains an unsafe and
		# a safe usage of $RANDOM, it will pass the test.

		# Strip comments.
		# Note: this has the side-effect that the # in $# is also
		# regarded as a comment.
		line="${line%%#*}"

		# Check for $RANDOM, which is specific to ksh and bash.
		case "$line" in
		*"\$\$-\$RANDOM"* \
		| *"\$RANDOM-\$\$"* \
		| *"\$RANDOM"[A-Z_]*)
			# When $RANDOM is prefixed by the process ID, it
			# doesn't matter too much if $RANDOM is empty.
			# This code is often found in GNU configure scripts.
			;;

		*\$RANDOM*)
			cs_warning_heading "Found \$RANDOM:"
			cs_warning_msg "$fname: $line"
			;;
		esac

		#
		# Split the line into words and check them.
		#
		set args $line; shift
		while [ $# -ge 3 ]; do
			case "$1" in
			"test" | "[")
				if [ "==" = "$3" ]; then
					cs_error_heading "Found test ... == ...:"
					cs_error_msg "$fname: $line"
				fi
				;;
			esac
			shift
		done

	done < "$1"
}

find * -type f -print 2>/dev/null \
| {
	while read fname; do

		eval "case \"\$fname\" in $SKIP_FILTER *.orig) continue;; esac"

		read firstline < "$fname" || continue
		case "$firstline" in
		"#!"*"/bin/sh")
			check_shell "$fname"
			;;
		esac
	done
	cs_exit
}
