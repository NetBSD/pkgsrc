$NetBSD: patch-testsuite_tests_opt__parse_usage_test.sh,v 1.1 2025/10/07 20:45:11 dkazankov Exp $

NetBSD's grep does not support PCRE

--- testsuite/tests/opt_parse/usage/test.sh.orig	2024-09-24 12:28:32.000000000 +0300
+++ testsuite/tests/opt_parse/usage/test.sh
@@ -8,27 +8,27 @@
 python parse_output.py
 
 # Check that the help text contains updated usage information
-if grep -P -q "\[--charset\|-C <charset name>\]" $STDOUT; then
+if grep -q -E "\[--charset\|-C <charset name>\]" $STDOUT; then
    echo "stdout contained new usage text for option"
 fi
 
-if grep -P -q "\[--day\|-D <three letter day of week>\]" $STDOUT; then
+if grep -q -E "\[--day\|-D <three letter day of week>\]" $STDOUT; then
    echo "stdout contained new usage text for enum option"
 fi
 
-if grep -P -q "\[--files\|-F <list of filepaths to parse>\]" $STDOUT; then
+if grep -q -E "\[--files\|-F <list of filepaths to parse>\]" $STDOUT; then
    echo "stdout contained new usage text for option list"
 fi
 
 # Check that the help text contains default usage information
-if grep -P -q "\[--charset2\|-C2 CHARSET2\]" $STDOUT; then
+if grep -q -E "\[--charset2\|-C2 CHARSET2\]" $STDOUT; then
    echo "stdout contained default usage text for option"
 fi
 
-if grep -P -q "\[--day2\|-D2 DAY2\]" $STDOUT; then
+if grep -q -E "\[--day2\|-D2 DAY2\]" $STDOUT; then
    echo "stdout contained default usage text for enum option"
 fi
 
-if grep -P -q "\[--files2\|-F2 FILES2 \[FILES2...\]\]" $STDOUT; then
+if grep -q -E "\[--files2\|-F2 FILES2 \[FILES2...\]\]" $STDOUT; then
    echo "stdout contained default usage text for option list"
 fi
