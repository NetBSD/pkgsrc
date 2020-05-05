#! /bin/sh
# $NetBSD: check-portability.sh,v 1.3 2020/05/05 05:55:25 rillig Exp $
#
# Test cases for mk/check/check-portability.*.
#

set -eu

. "./test.subr"

# Runs the shell program for the given file.
check_portability_sh() {
	env	PATCHDIR='patches' \
		PREFIX='/nonexistent' \
		"$@" \
		sh "$pkgsrcdir/mk/check/check-portability.sh" \
		1>"$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?
}

# Runs the AWK program in standalone mode for the given file.
check_portability_awk() {
	env	CK_FNAME="$1" \
		CK_PROGNAME='check-portability.awk' \
		awk	-f "$pkgsrcdir/mk/check/check-subr.awk" \
			-f "$pkgsrcdir/mk/check/check-portability.awk" \
			"$1" \
		1>"$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?
}

test_case_set_up() {
	rm -rf "$tmpdir/work"
	mkdir "$tmpdir/work"
	cd "$tmpdir/work"
}

# TODO: remove the "work/" from the tests.
# The $tmpdir must be a bit structured:
# $tmpdir/pkgsrc	these files override the actual pkgsrc files
# $tmpdir/work		current working directory


if test_case_begin "test ... = ..."; then

	create_file_lines 'work/file' \
		'if [ "$var" = value ]; then' \
		'  ...' \
		'elif test "$var" = value ]; then' \
		'  ...' \
		'fi'

	check_portability_awk 'file'

	assert_that 'out' --file-is-empty
	assert_that $exitcode --equals 0

	test_case_end
fi


if test_case_begin 'test ... == ...'; then

	create_file_lines 'work/file' \
		'if [ "$var" == value ]; then' \
		'  ...' \
		'elif test "$var" == value ]; then' \
		'  ...' \
		'fi'

	check_portability_awk 'file'

	create_file 'expected' <<'EOF'
ERROR: [check-portability.awk] => Found test ... == ...:
ERROR: [check-portability.awk] file:1: if [ "$var" == value ]; then
ERROR: [check-portability.awk] file:3: elif test "$var" == value ]; then

Explanation:
===========================================================================
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
===========================================================================

EOF
	assert_that 'out' --file-equals 'expected'
	assert_that $exitcode --equals 1

	test_case_end
fi


if test_case_begin 'configure patched, configure.in bad'; then

	create_file_lines 'work/patches/patch-aa' \
		'+++ configure 2020-05-04'
	create_file_lines 'work/configure' \
		'#! /bin/sh' \
		'good'
	create_file_lines 'work/configure.in' \
		'test a == b'

	check_portability_sh \
		'CHECK_PORTABILITY_EXPERIMENTAL=yes'

	assert_that "out" --file-is-empty
	assert_that $exitcode --equals 0

	test_case_end
fi


if test_case_begin 'configure patched and still bad'; then

	create_file_lines 'work/patches/patch-aa' \
		'+++ configure 2020-05-04'
	create_file_lines 'work/configure' \
		'#! /bin/sh' \
		'test a == b'

	check_portability_sh \
		'CHECK_PORTABILITY_EXPERIMENTAL=yes'

	create_file 'expected' <<'EOF'
ERROR: [check-portability.awk] => Found test ... == ...:
ERROR: [check-portability.awk] configure:2: test a == b

Explanation:
===========================================================================
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
===========================================================================

EOF
	assert_that 'out' --file-equals 'expected'
	assert_that $exitcode --equals 1

	test_case_end
fi


if test_case_begin 'special characters in filenames'; then

	# Ensure that the filename matching for patched files
	# does not treat special characters as shell metacharacters.

	create_file_lines 'work/patches/patch-aa' \
		'+++ [[[[(`" 2020-05-04'
	create_file_lines 'work/+++ [[[[(`"' \
		'#! /bin/sh' \
		'test a = b'

	check_portability_sh \
		'CHECK_PORTABILITY_EXPERIMENTAL=yes'

	assert_that 'out' --file-is-empty
	assert_that $exitcode --equals 0

	test_case_end
fi


if test_case_begin 'no patches'; then

	# Ensure that no error message is printed when there are no
	# patch files.

	create_file_lines 'file' \
		'#! /bin/sh' \
		'test a = b'

	check_portability_sh

	assert_that 'out' --file-is-empty
	assert_that $exitcode --equals 0

	test_case_end
fi


if test_case_begin 'no experimental by default'; then

	create_file_lines 'configure.in' \
		'test a == b'

	check_portability_sh \
		'CHECK_PORTABILITY_EXPERIMENTAL=no'

	assert_that 'out' --file-is-empty
	assert_that $exitcode --equals 0

	test_case_end
fi
