$NetBSD: patch-jdk_src_solaris_native_com_sun_security_auth_module_Unix.c,v 1.1 2018/07/24 12:58:45 jperkin Exp $

Fix build on SunOS with C99.

--- jdk/src/solaris/native/com/sun/security/auth/module/Unix.c.orig	2018-05-26 23:58:28.000000000 +0000
+++ jdk/src/solaris/native/com/sun/security/auth/module/Unix.c
@@ -24,7 +24,11 @@
  */
 
 #ifdef __solaris__
+#  if (__STDC_VERSION__ - 0 < 199901L)
 #define _POSIX_C_SOURCE 199506L
+#  else
+#define _POSIX_PTHREAD_SEMANTICS
+#  endif
 #endif
 
 #include <jni.h>
