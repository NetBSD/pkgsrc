$NetBSD: patch-make_autoconf_lib-bundled.m4,v 1.1 2019/10/01 12:36:34 tnn Exp $

Add rpath for zlib.

--- make/autoconf/lib-bundled.m4.orig	2019-09-19 12:22:38.000000000 +0000
+++ make/autoconf/lib-bundled.m4
@@ -257,7 +257,8 @@ AC_DEFUN_ONCE([LIB_SETUP_ZLIB],
   if test "x$USE_EXTERNAL_LIBZ" = "xfalse"; then
     LIBZ_CFLAGS="$LIBZ_CFLAGS -I$TOPDIR/src/java.base/share/native/libzip/zlib"
   else
-    LIBZ_LIBS="-lz"
+    LIBZ_CFLAGS="-I@BUILDLINK_PREFIX.zlib@/include"
+    LIBZ_LIBS="@COMPILER_RPATH_FLAG@@BUILDLINK_PREFIX.zlib@/lib -L@BUILDLINK_PREFIX.zlib@/lib -lz"
   fi
 
   AC_SUBST(USE_EXTERNAL_LIBZ)
