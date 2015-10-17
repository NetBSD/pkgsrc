$NetBSD: patch-tests_tests.sh,v 1.4 2015/10/17 17:57:28 khorben Exp $

Avoid building the (experimental) Python binding.
Use LD_LIBRARY_PATH to find pre-installed libraries.

--- tests/tests.sh.orig	2015-10-14 23:30:20.000000000 +0000
+++ tests/tests.sh
@@ -42,7 +42,7 @@ _run()
 	echo -n "$test:" 1>&2
 	(echo
 	echo "Testing: $test" "$@"
-	LD_LIBRARY_PATH="$OBJDIR../src" "$OBJDIR$test" "$@") 2>&1
+	env LD_LIBRARY_PATH="$OBJDIR../src" "$OBJDIR$test" "$@") 2>&1
 	res=$?
 	if [ $res -ne 0 ]; then
 		echo "Test: $test$sep$@: FAIL (error $res)"
@@ -107,7 +107,7 @@ _test "includes"
 _test "string"
 _test "variable"
 echo "Expected failures:" 1>&2
-_fail "python.sh"
+#_fail "python.sh"
 if [ -n "$FAILED" ]; then
 	echo "Failed tests:$FAILED" 1>&2
 	exit 2
