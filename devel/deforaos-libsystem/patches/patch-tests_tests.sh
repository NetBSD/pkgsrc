$NetBSD: patch-tests_tests.sh,v 1.5 2017/04/13 00:41:02 khorben Exp $

Avoid building the (experimental) Python binding.
Use LD_LIBRARY_PATH to find pre-installed libraries.

--- tests/tests.sh.orig	2017-04-13 00:29:45.000000000 +0000
+++ tests/tests.sh
@@ -114,8 +114,8 @@ failures=
 
 if $PKGCONFIG --exists python-2.7; then
 	tests="$tests python.sh"
-else
-	failures="$failures python.sh"
+#else
+#	failures="$failures python.sh"
 fi
 
 $DATE > "$target"
