$NetBSD: patch-testsuite_tests_opt__parse_help__whitespace_help__short__arg_test.sh,v 1.1 2025/10/07 20:45:11 dkazankov Exp $

NetBSD's grep does not support PCRE

--- testsuite/tests/opt_parse/help_whitespace/help_short_arg/test.sh.orig	2024-09-24 12:28:32.000000000 +0300
+++ testsuite/tests/opt_parse/help_whitespace/help_short_arg/test.sh
@@ -3,7 +3,7 @@
 ./test --help > $STDOUT
 
 # Check that the help message is structured as expected
-if ! grep -q -P "( ){4,}" $STDOUT; then
+if ! grep -q -E "^( ){4,}" $STDOUT; then
     # The biggest whitespace should be the three characters before optional
     # arguments as "--help, -h" and "--char, -C" are the same lenght, and
     # while they are less than 25 characters, the column number the help
