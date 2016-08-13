$NetBSD: patch-ext_gd_config.m4,v 1.2 2016/08/13 17:34:41 taca Exp $

--- ext/gd/config.m4.orig	2016-08-05 21:30:28.000000000 +0000
+++ ext/gd/config.m4
@@ -46,18 +46,7 @@ dnl Checks for the configure options
 dnl
 
 AC_DEFUN([PHP_GD_ZLIB],[
-	if test "$PHP_ZLIB_DIR" != "no" && test "$PHP_ZLIB_DIR" != "yes"; then
-		if test -f "$PHP_ZLIB_DIR/include/zlib/zlib.h"; then
-			PHP_ZLIB_DIR="$PHP_ZLIB_DIR"
-			PHP_ZLIB_INCDIR="$PHP_ZLIB_DIR/include/zlib"
-		elif test -f "$PHP_ZLIB_DIR/include/zlib.h"; then
-			PHP_ZLIB_DIR="$PHP_ZLIB_DIR"
-			PHP_ZLIB_INCDIR="$PHP_ZLIB_DIR/include"
-		else
-			AC_MSG_ERROR([Can't find zlib headers under "$PHP_ZLIB_DIR"])
-		fi
-	else
-		for i in /usr/local /usr; do
+		for i in "$PHP_ZLIB_DIR" /usr/local /usr; do
 			if test -f "$i/include/zlib/zlib.h"; then
 				PHP_ZLIB_DIR="$i"
 				PHP_ZLIB_INCDIR="$i/include/zlib"
@@ -66,7 +55,6 @@ AC_DEFUN([PHP_GD_ZLIB],[
 				PHP_ZLIB_INCDIR="$i/include"
 			fi
 		done
-	fi
 ])
 
 AC_DEFUN([PHP_GD_WEBP],[
@@ -143,13 +131,13 @@ AC_DEFUN([PHP_GD_PNG],[
       AC_MSG_ERROR([PNG support requires ZLIB. Use --with-zlib-dir=<DIR>])
     fi
 
-    PHP_CHECK_LIBRARY(png,png_write_image,
+    PHP_CHECK_LIBRARY(png16,png_write_image,
     [
       PHP_ADD_INCLUDE($GD_PNG_DIR/include)
       PHP_ADD_LIBRARY_WITH_PATH(z, $PHP_ZLIB_DIR/$PHP_LIBDIR, GD_SHARED_LIBADD)
-      PHP_ADD_LIBRARY_WITH_PATH(png, $GD_PNG_DIR/$PHP_LIBDIR, GD_SHARED_LIBADD)
+      PHP_ADD_LIBRARY_WITH_PATH(png16, $GD_PNG_DIR/$PHP_LIBDIR, GD_SHARED_LIBADD)
     ],[
-      AC_MSG_ERROR([Problem with libpng.(a|so) or libz.(a|so). Please check config.log for more information.])
+      AC_MSG_ERROR([Problem with libpng16.(a|so) or libz.(a|so). Please check config.log for more information.])
     ],[
       -L$PHP_ZLIB_DIR/$PHP_LIBDIR -lz -L$GD_PNG_DIR/$PHP_LIBDIR
     ])
@@ -230,7 +218,9 @@ AC_DEFUN([PHP_GD_CHECK_VERSION],[
   PHP_CHECK_LIBRARY(gd, gdImageCreateFromPng,   [AC_DEFINE(HAVE_GD_PNG,              1, [ ])], [], [ $GD_SHARED_LIBADD ])
   PHP_CHECK_LIBRARY(gd, gdImageCreateFromWebp,  [AC_DEFINE(HAVE_GD_WEBP,             1, [ ])], [], [ $GD_SHARED_LIBADD ])
   PHP_CHECK_LIBRARY(gd, gdImageCreateFromJpeg,  [AC_DEFINE(HAVE_GD_JPG,              1, [ ])], [], [ $GD_SHARED_LIBADD ])
-  PHP_CHECK_LIBRARY(gd, gdImageCreateFromXpm,   [AC_DEFINE(HAVE_GD_XPM,              1, [ ])], [], [ $GD_SHARED_LIBADD ])
+  if test "$PHP_XPM_DIR" != "no"; then
+    PHP_CHECK_LIBRARY(gd, gdImageCreateFromXpm,   [AC_DEFINE(HAVE_GD_XPM,              1, [ ])], [], [ $GD_SHARED_LIBADD ])
+  fi
   PHP_CHECK_LIBRARY(gd, gdImageStringFT,        [AC_DEFINE(HAVE_GD_FREETYPE,         1, [ ])], [], [ $GD_SHARED_LIBADD ])
   PHP_CHECK_LIBRARY(gd, gdVersionString,        [AC_DEFINE(HAVE_GD_LIBVERSION,       1, [ ])], [], [ $GD_SHARED_LIBADD ])
 ])
