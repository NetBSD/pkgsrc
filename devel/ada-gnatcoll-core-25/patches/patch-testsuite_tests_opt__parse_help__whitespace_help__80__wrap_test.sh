$NetBSD: patch-testsuite_tests_opt__parse_help__whitespace_help__80__wrap_test.sh,v 1.1 2025/10/07 20:45:11 dkazankov Exp $

NetBSD's grep does not support PCRE

--- testsuite/tests/opt_parse/help_whitespace/help_80_wrap/test.sh.orig	2024-09-24 12:28:32.000000000 +0300
+++ testsuite/tests/opt_parse/help_whitespace/help_80_wrap/test.sh
@@ -3,7 +3,7 @@
 ./test --help > $STDOUT
 
 # Check that the help message is structured as expected
-if ! grep -q -P ".{81,}" $STDOUT; then
+if ! grep -q -E "^.{81,}$" $STDOUT; then
     # Confirm that help text wraps at the 80 character limit as expected
     echo "Help text wrapped at 80 characters as expected"
 fi
