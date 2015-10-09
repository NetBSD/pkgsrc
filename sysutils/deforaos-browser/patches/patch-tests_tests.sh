$NetBSD: patch-tests_tests.sh,v 1.1 2015/10/09 22:33:13 khorben Exp $

Only run the "vfs" test when running under X

--- tests/tests.sh.orig	2015-10-05 23:01:10.000000000 +0000
+++ tests/tests.sh
@@ -99,7 +99,7 @@ $DATE > "$target"
 FAILED=
 echo "Performing tests:" 1>&2
 _test "plugins"
-_test "vfs"
+[ -z "$DISPLAY" ] || _test "vfs"
 #echo "Expected failures:" 1>&2
 #_fail "plugins"
 if [ -n "$FAILED" ]; then
