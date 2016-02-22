$NetBSD: patch-tests_tests.sh,v 1.1 2016/02/22 12:32:59 khorben Exp $

Avoid building the (experimental) Python binding.

--- tests/tests.sh.orig	2014-08-31 13:43:12.000000000 +0000
+++ tests/tests.sh
@@ -100,7 +100,7 @@ $DATE > "$target"
 FAILED=
 echo "Performing tests:" 1>&2
 echo "Expected failures:" 1>&2
-_fail "python.sh"
+#_fail "python.sh"
 if [ -n "$FAILED" ]; then
 	echo "Failed tests:$FAILED" 1>&2
 	exit 2
