#! /bin/sh
# $NetBSD: scripts-larger_symbol_version.sh,v 1.1 2020/06/06 14:02:18 rillig Exp $
#
# Tests for mk/scripts/larger_symbol_version.awk.
#

set -eu

. './test.subr'

test_case_set_up() {
	# nm -D /usr/lib/libgcc_s.so, on NetBSD 8.0.
	create_file 'nm-output' <<-EOF
		...
		0000000000000000 A GCC_3.0
		0000000000000000 A GCC_3.3
		0000000000000000 A GCC_3.3.1
		0000000000000000 A GCC_3.4
		0000000000000000 A GCC_3.4.2
		0000000000000000 A GCC_3.4.4
		...
		0000000000000000 A GCC_4.0.0
		0000000000000000 A GCC_4.7.0
		...
		                 w _Jv_RegisterClasses
		000000000000b852 T _Unwind_Backtrace
		000000000000b83e T _Unwind_DeleteException
		0000000000009a45 T _Unwind_FindEnclosingFunction
		                 U abort
		                 U calloc
		...
	EOF

	nm_cmd=$(mock_cmd mock-nm \
        	--when-args '-D /usr/lib/libgcc_s.so' \
		--then-output "$(cat nm-output)"
	)
}


if test_case_begin 'library newer than target'; then

	create_file_lines 'shared-libs' \
		'/usr/lib/libgcc_s.so 3.5'

	env NM="$nm_cmd" \
		awk -f "$pkgsrcdir/mk/scripts/larger_symbol_version.awk" \
			0<'shared-libs' 1>"$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'the version of /usr/lib/libgcc_s.so is newer than target version 3.5'
	assert_that "$exitcode" --equals '0'

	test_case_end
fi


if test_case_begin 'library equal to target'; then

	create_file_lines 'shared-libs' \
		'/usr/lib/libgcc_s.so 4.7'

	env NM="$nm_cmd" \
		awk -f "$pkgsrcdir/mk/scripts/larger_symbol_version.awk" \
			0<'shared-libs' 1>"$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'the version of /usr/lib/libgcc_s.so is older or equal to target version 4.7'
	assert_that "$exitcode" --equals '0'

	test_case_end
fi


if test_case_begin 'library older than target'; then

	create_file_lines 'shared-libs' \
		'/usr/lib/libgcc_s.so 8.0'

	env NM="$nm_cmd" \
		awk -f "$pkgsrcdir/mk/scripts/larger_symbol_version.awk" \
			0<'shared-libs' 1>"$tmpdir/output" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "$tmpdir/output" --file-is-lines \
		'the version of /usr/lib/libgcc_s.so is older or equal to target version 8.0'
	assert_that "$exitcode" --equals '0'

	test_case_end
fi
