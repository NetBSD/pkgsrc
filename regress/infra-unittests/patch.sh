#! /bin/sh
# $NetBSD: patch.sh,v 1.1 2020/04/26 12:46:01 rillig Exp $
#
# Test cases for patching files using patch(1).
#

set -eu

. "./test.subr"

if test_case_begin "patch matches exactly"; then
	cd "$tmpdir"

	create_file_lines "to-be-patched" \
		"1" "2" "3" "4" "5" "6" "7"

	create_file "4-four.patch" <<EOF
--- before
+++ to-be-patched
@@ -1,7 +1,7 @@
 1
 2
 3
-4
+four
 5
 6
 7
EOF

	patch -s -p0 < "4-four.patch"

	assert_that "to-be-patched" --file-is-lines \
		"1" "2" "3" "four" "5" "6" "7"

	test_case_end
fi


if test_case_begin "line numbers in patch are way out of bounds"; then
	cd "$tmpdir"

	# BSD patch:
	#
	# If the line numbers in the patch are beyond the size of the file,
	# /usr/bin/patch logs an information that "it is ignored", but it does
	# not say exactly what "it" is.
	#
	# This may look frightening, but since the patch is applied anyway,
	# "it" probably refers to the line numbers only, not to the hunk as
	# a whole.
	#
	# https://github.com/openbsd/src/commit/328a6cea628e2916 (2003-07-16)

	create_file_lines "to-be-patched" \
		"1" "2" "3" "4" "5" "6" "7"

	create_file "4-four.patch" <<EOF
--- before
+++ to-be-patched
@@ -1000,7 +1000,7 @@
 1
 2
 3
-4
+four
 5
 6
 7
EOF

	patch -s -p0 < "4-four.patch" 2> "stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "$exitcode" --equals "0"
	assert_that "stderr" --file-is-lines \
		"No such line 999 in input file, ignoring"
	assert_that "to-be-patched" --file-is-lines \
		"1" "2" "3" "four" "5" "6" "7"

	test_case_end
fi
