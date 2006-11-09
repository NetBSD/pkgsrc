# $NetBSD: check-portability.sh,v 1.2 2006/11/09 10:52:21 rillig Exp $
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
			found_random=yes
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
					found_test_eqeq=yes
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

	if [ $found_random = yes ]; then
		cs_explain <<EOF
The variable \$RANDOM is not required for a POSIX-conforming shell, and
many implementations of /bin/sh do not support it. It should therefore
not be used in shell programs that are meant to be portable across a
large number of POSIX-like systems.
EOF
	fi

	if [ $found_test_eqeq = yes ]; then
		cs_explain <<EOF
The "test" command, as well as the "[" command, are not required to know
the "==" operator. Only a few implementations like bash and some
versions of ksh support it.

When you run "test foo == foo" on a platform that does not support the
"==" operator, the result will be "false" instead of "true". This can
lead to unexpected behavior.

There are two ways to fix this error message. If the file that contains
the "test ==" is needed for building the package, you should create a
patch for it, replacing the "==" operator with "=". If the file is not
needed, add its name to the CHECK_PORTABILITY_SKIP variable in the
package Makefile.
EOF
	fi

	cs_exit
}
