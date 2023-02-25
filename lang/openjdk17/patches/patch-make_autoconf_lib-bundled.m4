$NetBSD: patch-make_autoconf_lib-bundled.m4,v 1.2 2023/02/25 18:11:31 ryoon Exp $

Add rpath for zlib.

--- make/autoconf/lib-bundled.m4.orig	2022-11-02 17:07:48.842199354 +0000
+++ make/autoconf/lib-bundled.m4
@@ -264,7 +264,8 @@ AC_DEFUN_ONCE([LIB_SETUP_ZLIB],
         LIBZ_CFLAGS="$LIBZ_CFLAGS -DHAVE_UNISTD_H"
     fi
   else
-    LIBZ_LIBS="-lz"
+    LIBZ_CFLAGS="-I@BUILDLINK_PREFIX.zlib@/include"
+    LIBZ_LIBS="@COMPILER_RPATH_FLAG@@BUILDLINK_PREFIX.zlib@/lib -L@BUILDLINK_PREFIX.zlib@/lib -lz"
   fi
 
   AC_SUBST(USE_EXTERNAL_LIBZ)
