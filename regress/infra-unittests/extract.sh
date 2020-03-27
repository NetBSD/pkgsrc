#! /bin/sh
#
# Tests for mk/subst.mk.
#
set -eu

. "./test.subr"

test_case_set_up() {
	# XXX: The mocked pkgsrc directory should be somewhere else.
	rm -rf "$tmpdir/pkgsrc" "$tmpdir/expected"

	cd "$tmpdir"

	LC_ALL=C
	export LC_ALL
}

if test_case_begin "exclude directory by basename"; then

	# Demonstrates that excluding a directory name also excludes that
	# directory further down in the hierarchy.
	#
	# For example, with BSD tar and GNU tar it is not possible to exclude
	# only the top-level "contrib" directory but still extract other
	# contrib directories.
	#
	# Experienced in lang/gcc*, which has contrib/ and java-lib/contrib/.

	create_file_lines "contrib/file"	"content"
	create_file_lines "other/file"		"content"
	create_file_lines "other/contrib/file"	"content"

	tar cf "archive.tar" "contrib" "other"
	rm -r "contrib" "other"

	sh "$pkgsrcdir/mk/extract/extract" -x "archive.tar" "contrib"

	find . -print | sort > "extracted"

	assert_that "extracted" --file-is-lines \
		"." \
		"./archive.tar" \
		"./extracted" \
		"./other" \
		"./other/file"

	test_case_end
fi

if test_case_begin "try to exclude directory by pattern with slash"; then

	# Having exclusion patterns with slash does not work at all for
	# the default tar extractor. The patterns are matched against
	# the basename of the file to be extracted, and that basename
	# obviously cannot contain a slash.

	create_file_lines "contrib/file"	"content"
	create_file_lines "other/file"		"content"
	create_file_lines "other/contrib/file"	"content"

	tar cf "archive.tar" "contrib" "other"
	rm -r "contrib" "other"

	sh "$pkgsrcdir/mk/extract/extract" -x "archive.tar" "contrib/*"

	find . -print | sort > "extracted"

	assert_that "extracted" --file-is-lines \
		"." \
		"./archive.tar" \
		"./contrib" \
		"./extracted" \
		"./other" \
		"./other/contrib" \
		"./other/file"

	test_case_end
fi

if test_case_begin "exclude asterisk"; then

	# Ensure that the exclusion pattern "*" is not expanded by the
	# shell but passed as-is to the extractor.

	create_file_lines "contrib/file"	"content"
	create_file_lines "other/file"		"content"
	create_file_lines "other/contrib/file"	"content"

	tar cf "archive.tar" "contrib" "other"
	rm -r "contrib" "other"

	sh "$pkgsrcdir/mk/extract/extract" -x "archive.tar" "*"

	find . -print | sort > "extracted"

	assert_that "extracted" --file-is-lines \
		"." \
		"./archive.tar" \
		"./extracted"

	test_case_end
fi

# TODO: test -x on an archiver that doesn't support it.

# TODO: add test for extracting only a few files.
