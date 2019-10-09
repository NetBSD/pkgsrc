$NetBSD: patch-tests_tests.sh,v 1.6 2019/10/09 01:58:56 khorben Exp $

Avoid building the (experimental) Python binding.

--- tests/tests.sh.orig	2019-08-29 00:00:20.000000000 +0000
+++ tests/tests.sh
@@ -119,21 +119,6 @@ fi
 
 tests="array buffer config error event includes parser string variable"
 failures=
-$PKGCONFIG --exists "python-2.7"
-case $? in
-	127)
-		failures="pkgconfig.sh python.sh"
-		;;
-	0)
-		if [ -n "$PKG_CONFIG_SYSROOT_DIR" ]; then
-			#XXX cross-compiling
-			tests="pkgconfig.sh python.sh"
-		fi
-		;;
-	*)
-		failures="$failures python.sh"
-		;;
-esac
 
 while [ $# -ne 0 ]; do
 	target="$1"
