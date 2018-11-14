$NetBSD: patch-ext_gd_config.m4,v 1.3 2018/11/14 21:26:53 markd Exp $

Allow pkg-config rather than freetype-config

--- ext/gd/config.m4.orig	2018-09-11 06:26:58.000000000 +0000
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
@@ -189,6 +177,9 @@ AC_DEFUN([PHP_GD_XPM],[
 AC_DEFUN([PHP_GD_FREETYPE2],[
   if test "$PHP_FREETYPE_DIR" != "no"; then
 
+    AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
+
+    AC_MSG_CHECKING([for freetype])
     for i in $PHP_FREETYPE_DIR /usr/local /usr; do
       if test -f "$i/bin/freetype-config"; then
         FREETYPE2_DIR=$i
@@ -197,13 +188,20 @@ AC_DEFUN([PHP_GD_FREETYPE2],[
       fi
     done
 
-    if test -z "$FREETYPE2_DIR"; then
+    if test -n "$FREETYPE2_CONFIG"; then
+      FREETYPE2_CFLAGS=`$FREETYPE2_CONFIG --cflags`
+      FREETYPE2_LIBS=`$FREETYPE2_CONFIG --libs`
+      AC_MSG_RESULT([found in $FREETYPE2_DIR])
+    elif test "$PKG_CONFIG" != "no" && $PKG_CONFIG --exists freetype2; then
+      FREETYPE2_DIR=pkg-config
+      FREETYPE2_CFLAGS=`$PKG_CONFIG freetype2 --cflags`
+      FREETYPE2_LIBS=`$PKG_CONFIG freetype2 --libs`
+      AC_MSG_RESULT([found by pkg-config])
+    else
+      AC_MSG_RESULT([not found])
       AC_MSG_ERROR([freetype-config not found.])
     fi
 
-    FREETYPE2_CFLAGS=`$FREETYPE2_CONFIG --cflags`
-    FREETYPE2_LIBS=`$FREETYPE2_CONFIG --libs`
-
     PHP_EVAL_INCLINE($FREETYPE2_CFLAGS)
     PHP_EVAL_LIBLINE($FREETYPE2_LIBS, GD_SHARED_LIBADD)
     AC_DEFINE(USE_GD_IMGSTRTTF, 1, [ ])
@@ -230,7 +228,9 @@ AC_DEFUN([PHP_GD_CHECK_VERSION],[
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
