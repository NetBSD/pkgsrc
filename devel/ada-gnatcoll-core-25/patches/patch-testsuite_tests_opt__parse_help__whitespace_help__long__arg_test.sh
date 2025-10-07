$NetBSD: patch-testsuite_tests_opt__parse_help__whitespace_help__long__arg_test.sh,v 1.1 2025/10/07 20:45:11 dkazankov Exp $

NetBSD's grep does not support PCRE

--- testsuite/tests/opt_parse/help_whitespace/help_long_arg/test.sh.orig	2024-09-24 12:28:32.000000000 +0300
+++ testsuite/tests/opt_parse/help_whitespace/help_long_arg/test.sh
@@ -3,7 +3,7 @@
 ./test --help > $STDOUT
 
 # Check that the help message is structured as expected
-if grep -q -P "( ){20,}" $STDOUT; then
+if grep -q -E "^( ){20,}" $STDOUT; then
     # Opposite to help_short_80. There should be more than 20 spaces, which
     # was the previous limit after a single character arg like "-c" and a
     # fixed 25 character column
