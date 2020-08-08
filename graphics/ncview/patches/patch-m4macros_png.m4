$NetBSD: patch-m4macros_png.m4,v 1.1 2020/08/08 22:18:27 brook Exp $

Use pkg-config to define compiler flags for libpng.

--- m4macros/png.m4.orig	2016-03-20 17:45:53.000000000 +0000
+++ m4macros/png.m4
@@ -56,6 +56,10 @@ if test x$PNG_INCDIR = x; then
         AC_CHECK_HEADER( /sw/include/png.h, PNG_INCDIR=/sw/include )
 fi
 dnl
+if test x$PNG_INCDIR = x; then
+	PNG_INC_PRESENT=yes
+        PNG_CPPFLAGS=`pkg-config --cflags-only-I libpng`
+else
 PNG_INC_PRESENT=no
 if test x$PNG_INCDIR != x; then
 	PNG_INC_PRESENT=yes
@@ -64,6 +68,7 @@ else
 	echo "** Could not find the png.h file, so -frames support will not be included  **"
 	echo "** Install the PNG library (and development headers) to fix this           **"
 fi
+fi
 dnl =================================================================================
 dnl check for png lib directory
 dnl
@@ -107,6 +112,11 @@ if test $PNG_INC_PRESENT = yes; then
 		PNG_LIBS=-l$PNG_LIBNAME
 		PNG_LDFLAGS="-L$PNG_LIBDIR $PNG_LIBS"
 		AC_DEFINE([HAVE_PNG],1,[Define if you have PNG library])
+	else
+		PNG_PRESENT=yes
+		PNG_LIBS=`pkg-config --libs-only-l libpng`
+		PNG_LDFLAGS=`pkg-config --libs libpng`
+		AC_DEFINE([HAVE_PNG],1,[Define if you have PNG library])
 	fi
 fi
 dnl
