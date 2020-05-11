#! /bin/sh
# $NetBSD: extract.sh,v 1.5 2020/05/11 19:13:10 rillig Exp $
#
# Test cases for mk/extract/extract.
#

set -eu

. "./test.subr"

test_case_set_up() {
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

	tar cf "$tmpdir/archive.tar" "contrib" "other"
	rm -r "contrib" "other"

	sh "$pkgsrcdir/mk/extract/extract" -x "$tmpdir/archive.tar" "contrib"

	find . -print | sort > "$tmpdir/extracted"

	assert_that "$tmpdir/extracted" --file-is-lines \
		"." \
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

	tar cf "$tmpdir/archive.tar" "contrib" "other"
	rm -r "contrib" "other"

	sh "$pkgsrcdir/mk/extract/extract" -x "$tmpdir/archive.tar" "contrib/*"

	find . -print | sort > "$tmpdir/extracted"

	assert_that "$tmpdir/extracted" --file-is-lines \
		"." \
		"./contrib" \
		"./other" \
		"./other/contrib" \
		"./other/file"

	test_case_end
fi

if test_case_begin "exclude asterisk"; then

	# Ensure that the exclusion pattern "*" is not expanded by the
	# shell but passed as-is to the extractor.
	#
	# If the pattern were expanded, it would expand to 'expanded'
	# and would thus not exclude anything from the actual archive,
	# which means that all files in the archive would be extracted.

	create_file_lines "contrib/file"	"content"
	create_file_lines "other/file"		"content"
	create_file_lines "other/contrib/file"	"content"

	tar cf "$tmpdir/archive.tar" "contrib" "other"
	rm -r "contrib" "other"

	> 'expanded'
	sh "$pkgsrcdir/mk/extract/extract" -x "$tmpdir/archive.tar" "*"
	rm 'expanded'

	find . -print | sort > "$tmpdir/extracted"

	assert_that "$tmpdir/extracted" --file-is-lines \
		"."

	test_case_end
fi

# TODO: test -x on an archiver that doesn't support it.

# TODO: add test for extracting only a few files.
