#! /bin/sh
#
# Tests for mk/subst.mk.
#
set -eu

. "./test.subr"

# XXX: The mocked pkgsrc directory should be somewhere else.
rm -r "$tmpdir/pkgsrc"

# XXX: This definition should be available everywhere.
pkgsrcdir="`cd "$real_pkgsrcdir" && exec pwd`"

if test_case_begin "exclude directory"; then

	# Demonstrates that excluding a directory name also excludes that
	# directory further down in the hierarchy.
	#
	# For example, with BSD tar and GNU tar it is not possible to exclude
	# only the top-level "contrib" directory but still extract other
	# contrib directories.
	#
	# Experienced in lang/gcc*, which has contrib/ and java-lib/contrib/.

	cd "$tmpdir"
	mkdir "contrib"
	echo "file" > "contrib/file"
	mkdir "other"
	echo "file" > "other/file"
	mkdir "other/contrib"
	echo "file" > "other/contrib/file"

	tar cf "archive.tar" "contrib" "other"
	rm -r "contrib" "other"

	sh "$pkgsrcdir/mk/extract/extract" -x "archive.tar" "contrib"

	find . -print | LC_ALL=C sort > "extracted"

	assert_that "extracted" --file-is-lines \
		"." \
		"./archive.tar" \
		"./extracted" \
		"./other" \
		"./other/file"

	test_case_end
fi
