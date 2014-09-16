$NetBSD: patch-tests_tests.sh,v 1.1 2014/09/16 19:25:51 khorben Exp $

Avoid building the (experimental) Python binding.

--- tests/tests.sh.orig	2014-08-29 19:23:48.000000000 +0000
+++ tests/tests.sh
@@ -103,7 +103,7 @@ _test "includes"
 _test "string"
 _test "variable"
 echo "Expected failures:" 1>&2
-_fail "python.sh"
+#_fail "python.sh"
 if [ -n "$FAILED" ]; then
 	echo "Failed tests:$FAILED" 1>&2
 	exit 2
