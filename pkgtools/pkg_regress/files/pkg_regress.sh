#! @SH@
#
# $NetBSD: pkg_regress.sh,v 1.6 2016/06/11 10:31:06 rillig Exp $
#
set -e

: ${PKGSRCDIR="@PKGSRCDIR@"}
: ${TEST_EGREP="@EGREP@"}
: ${TEST_MAKE="@MAKE@"}

# hooks overridable by test spec file

do_setup() {
	return
}

do_cleanup() {
	return
}

do_test() {
	do_test_default
}

check_result() {
	return
}

# Internal helper functions

do_test_default() {
	# The if is necessary to prevent sh -e from exiting.
	if $TEST_MAKE $MAKEARGS_TEST >$TEST_OUTFILE 2>&1; then
		TEST_EXITSTATUS=$?
	else
		TEST_EXITSTATUS=$?
	fi
}

# usage: regress_fail msg...
regress_fail() {

	echo "ERROR: $*" 1>&2
	TEST_RESULT=1
}

# result checking routines

# Text exit status
exit_status() {

	[ "$1" -eq "$TEST_EXITSTATUS" ] \
	|| regress_fail "Expected exit code $1, but got $TEST_EXITSTATUS."
}

# Test positive match against output
output_require() {

	for re in "$@"; do
		$TEST_EGREP "$re" < $TEST_OUTFILE >/dev/null \
		|| regress_fail "Expected \"$re\" in the output, but it is not there."
	done
}

# Test negative match against output
output_prohibit() {

	for re in "$@"; do
		if $TEST_EGREP "$re" < $TEST_OUTFILE >/dev/null; then
			regress_fail "Didn't expect \"$re\" in the output, but found it."
		fi
	done
}

do_runtest() {
	cd "$1"
	TEST_RESULT=0
	TEST_EXITSTATUS=0
	TEST_OUTFILE=`mktemp -t pkg_regress` || exit 1
	. ./spec

	do_setup

	do_test

	check_result

	# Perform cleanup

	do_cleanup

	if [ -n "${MAKEARGS_CLEAN-}" ]; then
		$TEST_MAKE $MAKEARGS_CLEAN >>$TEST_OUTFILE
	fi

	if [ "$verbose" = "yes" ]; then
		cat $TEST_OUTFILE
	fi

	rm -f $TEST_OUTFILE
	exit $TEST_RESULT
}

# runtest runs a test in a subshell, so that environment settings etc in
# one test do not interfere with other tests.
runtest() {
	if [ "$verbose" = "yes" ]; then
		echo "Running $1"
	fi

	if (do_runtest "$1"); then
		passed=`expr $passed + 1`
	else
		failed=`expr $failed + 1`
		failed_names="$failed_names $1"
    	fi
}

verbose=no
passed=0
failed=0
failed_names=""

cd $PKGSRCDIR/regress

while [ $# -gt 0 ]; do
	case "$1" in
	-v) shift; verbose=yes;;
	--) shift; break;;
	-*) echo "usage: $0 [-v] [directory...]" 1>&2; exit 1 ;;
	*) break
	esac
done

if [ $# -eq 0 ]; then
	set -- *
fi

for dir in "$@"; do
	if [ -f $dir/spec ]; then
		runtest $dir
	fi
done

if [ -n "$failed_names" ]; then
	echo "Tests failed:$failed_names"
	echo
fi

echo "Statistics:"
echo "  $passed passed, $failed failed"
