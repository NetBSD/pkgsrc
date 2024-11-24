#! /bin/sh
# $NetBSD: extract.sh,v 1.6 2024/11/24 08:22:47 rillig Exp $
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

if test_case_begin "exclude directory by pattern with slash"; then

	# The exclusion patterns may contain slashes. These patterns are
	# matched against the full pathname to be extracted, but they are
	# not anchored at the beginning of the pathname.

	create_file_lines "contrib/file"	"content"
	create_file_lines "other/file"		"content"
	create_file_lines "other/contrib/file"	"content"

	tar cf "$tmpdir/archive.tar" "contrib" "other"
	rm -r "contrib" "other"

	sh "$pkgsrcdir/mk/extract/extract" -x "$tmpdir/archive.tar" "contrib/*"

	find . -print | sort > "$tmpdir/extracted"

	assert_that "$tmpdir/extracted" --file-is-lines \
		"." \
		"./other" \
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
