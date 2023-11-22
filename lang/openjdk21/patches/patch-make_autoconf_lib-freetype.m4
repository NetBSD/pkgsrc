$NetBSD: patch-make_autoconf_lib-freetype.m4,v 1.1 2023/11/22 14:06:50 ryoon Exp $

Add rpath for freetype.

--- make/autoconf/lib-freetype.m4.orig	2022-02-05 03:44:09.000000000 +0000
+++ make/autoconf/lib-freetype.m4
@@ -231,7 +231,7 @@ AC_DEFUN_ONCE([LIB_SETUP_FREETYPE],
     fi
 
     if test "x$FREETYPE_LIBS" = "x" ; then
-      FREETYPE_LIBS="-L$FREETYPE_LIB_PATH -l$FREETYPE_BASE_NAME"
+      FREETYPE_LIBS="@COMPILER_RPATH_FLAG@$FREETYPE_LIB_PATH -L$FREETYPE_LIB_PATH -l$FREETYPE_BASE_NAME"
     fi
   fi
 
