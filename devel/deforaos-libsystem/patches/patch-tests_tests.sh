$NetBSD: patch-tests_tests.sh,v 1.2 2014/09/23 12:06:49 jperkin Exp $

Avoid building the (experimental) Python binding.
Use LD_LIBRARY_PATH to find pre-installed libraries.

--- tests/tests.sh.orig	2014-08-29 19:23:48.000000000 +0000
+++ tests/tests.sh
@@ -50,7 +50,7 @@
 	echo -n "$test:" 1>&2
 	(echo
 	echo "Testing: ./$test" "$@"
-	"./$test" "$@") >> "$target" 2>&1
+	env LD_LIBRARY_PATH=../src "./$test" "$@") >> "$target" 2>&1
 	res=$?
 	if [ $res -ne 0 ]; then
 		echo " FAIL" 1>&2
@@ -103,7 +103,7 @@ _test "includes"
 _test "string"
 _test "variable"
 echo "Expected failures:" 1>&2
-_fail "python.sh"
+#_fail "python.sh"
 if [ -n "$FAILED" ]; then
 	echo "Failed tests:$FAILED" 1>&2
 	exit 2
