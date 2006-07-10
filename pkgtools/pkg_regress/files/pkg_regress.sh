#! @SH@
#
# $NetBSD: pkg_regress.sh,v 1.4 2006/07/10 12:44:19 rillig Exp $
#
set -e

: ${PKGSRCDIR="@PKGSRCDIR@"}
: ${TEST_EGREP="@EGREP@"}
: ${TEST_MAKE="@MAKE@"}

# hooks overridable by test spec file

do_setup()
{
	return
}

do_cleanup()
{
	return
}

do_test()
{
	do_test_default
}

do_test_default()
{
	# Run the test. We use an if statement to ensure that the script
	# isn't terminated if it is executed with sh -e.
	if ${TEST_MAKE} ${MAKEARGS_TEST} >${TEST_OUTFILE} 2>&1
	then
	    TEST_EXITSTATUS=$?
	else
	    TEST_EXITSTATUS=$?
	fi
}

check_result()
{
	return
}

#
# Internal helper routines
#

# regress_fail <msg>
regress_fail() {

	echo "ERROR: $*" 1>&2
	TEST_RESULT=1
}

# result checking routines

# Test exit status
exit_status()
{

	[ "$1" -eq "${TEST_EXITSTATUS}" ] \
	|| regress_fail "Expected exit code $1, but got ${TEST_EXITSTATUS}."
}

# Test positive match against output
output_require()
{

	for re in "$@"; do
		${TEST_EGREP} "${re}" < ${TEST_OUTFILE} >/dev/null \
		|| regress_fail "Expected \"${re}\" in the output, but it is not there."
	done
}

# Test negative match against output
output_prohibit()
{

	for re in "$@"; do
		if ${TEST_EGREP} "${re}" < ${TEST_OUTFILE} >/dev/null; then
			regress_fail "Didn't expect \"${re}\" in the output, but found it."
		fi
	done
}

# runtest runs a test in a subshell, so that environment settings etc in
# one test do not interfere with other tests.
runtest() {
    if (
	cd $1
	TEST_RESULT=0
	TEST_EXITSTATUS=0
	TEST_OUTFILE=`mktemp -t pkg_regress` || exit 1
	. ./spec

	do_setup

	do_test

	check_result

	# Perform cleanup

	do_cleanup

	if [ -n "${MAKEARGS_CLEAN}" ]
	then
	    ${TEST_MAKE} ${MAKEARGS_CLEAN} >>${TEST_OUTFILE}
	fi

	if [ -n "${TEST_VERBOSE}" ]
	then
	    cat ${TEST_OUTFILE}
	fi

	rm -f ${TEST_OUTFILE}
	exit ${TEST_RESULT}
    )
    then
	TEST_PASS=`expr ${TEST_PASS} + 1`
    else
	TEST_FAIL=`expr ${TEST_FAIL} + 1`
	TEST_FAILURES="${TEST_FAILURES} $1"
    fi
}


TEST_PASS=0
TEST_FAIL=0
TEST_FAILURES=

cd $PKGSRCDIR/regress

case $1 in
    -v) TEST_VERBOSE=1
	shift ;;
esac

if [ $# -ne 0 ]
then
    TEST_LIST="$@"
else
    TEST_LIST="*"
fi

for dir in ${TEST_LIST}
do
    if [ -f $dir/spec ]
    then
	runtest $dir
    fi
done

if [ -n "${TEST_FAILURES}" ]
then
    echo "Tests failed: ${TEST_FAILURES}"
    echo
fi

echo "Statistics:"
echo "  $TEST_PASS passed, $TEST_FAIL failed"
