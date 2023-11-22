$NetBSD: patch-make_autoconf_lib-alsa.m4,v 1.1 2023/11/22 14:06:50 ryoon Exp $

* Fix RPATH for libasound.so. These should use COMPILER_RPATH_FLAG.

--- make/autoconf/lib-alsa.m4.orig	2021-04-24 02:47:22.000000000 +0000
+++ make/autoconf/lib-alsa.m4
@@ -52,7 +52,7 @@ AC_DEFUN_ONCE([LIB_SETUP_ALSA],
     fi
 
     if test "x${with_alsa}" != x; then
-      ALSA_LIBS="-L${with_alsa}/lib -lasound"
+      ALSA_LIBS="-L${with_alsa}/lib -Wl,-rpath,${with_alsa}/lib -lasound"
       ALSA_CFLAGS="-I${with_alsa}/include"
       ALSA_FOUND=yes
     fi
@@ -61,7 +61,7 @@ AC_DEFUN_ONCE([LIB_SETUP_ALSA],
       ALSA_FOUND=yes
     fi
     if test "x${with_alsa_lib}" != x; then
-      ALSA_LIBS="-L${with_alsa_lib} -lasound"
+      ALSA_LIBS="-L${with_alsa_lib} -Wl,-rpath,${with_alsa}/lib -lasound"
       ALSA_FOUND=yes
     fi
     # Do not try pkg-config if we have a sysroot set.
