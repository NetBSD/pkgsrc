$NetBSD: patch-src_libcollectclient_network__buffer.c,v 1.3 2016/12/07 17:28:39 fhajny Exp $

Need the workaround on at least SunOS too.
--- src/libcollectdclient/network_buffer.c.orig	2016-11-30 08:52:01.316911197 +0000
+++ src/libcollectdclient/network_buffer.c
@@ -36,7 +36,7 @@
 #include <pthread.h>
 
 #if HAVE_LIBGCRYPT
-#if defined __APPLE__
+#if defined __APPLE__ || defined(__sun)
 /* default xcode compiler throws warnings even when deprecated functionality
  * is not used. -Werror breaks the build because of erroneous warnings.
  * http://stackoverflow.com/questions/10556299/compiler-warnings-with-libgcrypt-v1-5-0/12830209#12830209
@@ -49,7 +49,7 @@
  */
 #define GCRYPT_NO_DEPRECATED
 #include <gcrypt.h>
-#if defined __APPLE__
+#if defined __APPLE__ || defined(__sun)
 /* Re enable deprecation warnings */
 #pragma GCC diagnostic warning "-Wdeprecated-declarations"
 #endif
