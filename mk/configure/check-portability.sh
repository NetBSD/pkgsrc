# $NetBSD: check-portability.sh,v 1.5 2006/10/29 20:12:49 rillig Exp $
#
# This program checks the extracted files for portability issues that
# are likely to result in false assumptions by the package.
#
# The most prominent example is the "==" operator of test(1), which is
# only implemented by bash and some versions of the ksh.
#
# Note: because this program is run with the tools wrapper directory in
# the PATH, it calls the utilities by their base names. It also assumes
# to be interpreted by a POSIX-conforming shell.
#
# ENVIRONMENT VARIABLES
#
#	SKIP_FILTER: A shell command that excludes some patterns.
#
# See also:
#	mk/configure/check-portability.mk
#

set -eu

: ${SKIP:=""}

exitcode=0

last_heading=""

error_msg() {
	echo "ERROR: [check-portability.sh] $*" 1>&2
	exitcode=1
}

warning_msg() {
	echo "WARNING: [check-portability.sh] $*" 1>&2
}

error_heading() {
	if test "$1" != "$last_heading"; then
		last_heading="$1"
		error_msg "=> $1"
	fi
}

warning_heading() {
	if test "$1" != "$last_heading"; then
		last_heading="$1"
		warning_msg "=> $1"
	fi
}

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
			warning_heading "Found \$RANDOM:"
			warning_msg "$fname: $line"
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
					error_heading "Found test ... == ...:"
					error_msg "$fname: $line"
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
	exit $exitcode
}
