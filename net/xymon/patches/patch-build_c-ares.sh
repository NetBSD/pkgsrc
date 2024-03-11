$NetBSD: patch-build_c-ares.sh,v 1.1 2024/03/11 10:47:29 jperkin Exp $

Link against c-ares library correctly.

--- build/c-ares.sh.orig	2024-03-11 10:39:55.043372385 +0000
+++ build/c-ares.sh
@@ -42,7 +42,7 @@
 	CARESOK="YES"
 	cd build
 	if test "$CARESINC" != ""; then INCOPT="-I$CARESINC"; fi
-	if test "$CARESLIB" != ""; then LIBOPT="-L$CARESLIB"; fi
+	if test "$CARESLIB" != ""; then LIBOPT="@COMPILER_RPATH_FLAG@$CARESLIB -L$CARESLIB"; fi
 	OS=`uname -s | sed -e's@/@_@g'` $MAKE -f Makefile.test-cares ares-clean
 	OS=`uname -s | sed -e's@/@_@g'` CARESINC="$INCOPT" $MAKE -f Makefile.test-cares test-compile
 	if test $? -eq 0; then
