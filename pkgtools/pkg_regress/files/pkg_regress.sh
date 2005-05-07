#!@SH@ -e
#
# $NetBSD: pkg_regress.sh,v 1.3 2005/05/07 15:46:00 gavan Exp $
#

if [ -z "$PKGSRCDIR" ]
then
    PKGSRCDIR=@PKGSRCDIR@
fi

TEST_EGREP="@EGREP@"
TEST_MAKE="@MAKE@"

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

# result checking routines

exit_status()
{
	# Test exit status
	if [ "$1" -ne "${TEST_EXITSTATUS}" ]
	then
	    TEST_RESULT=1
	fi
}

output_require()
{
	# Test positive match against output
	for PATTERN in "$@"
	do
	    if ! ${TEST_EGREP} -q "${PATTERN}" <${TEST_OUTFILE} >/dev/null
	    then
	        TEST_RESULT=1
	    fi
	done
}

output_prohibit()
{
	# Test negative match against output
	for PATTERN in "$@"
	do
	    if ${TEST_EGREP} -q "${PATTERN}" <${TEST_OUTFILE} >/dev/null
	    then
	        TEST_RESULT=1
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
