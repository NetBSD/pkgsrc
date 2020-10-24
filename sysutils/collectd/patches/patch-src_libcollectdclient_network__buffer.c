$NetBSD: patch-src_libcollectdclient_network__buffer.c,v 1.1 2020/10/24 22:39:45 wiz Exp $

Need the workaround on at least SunOS too.

--- src/libcollectdclient/network_buffer.c.orig	2020-03-08 16:57:09.000000000 +0100
+++ src/libcollectdclient/network_buffer.c	2020-07-06 19:48:22.130670698 +0200
@@ -41,7 +41,7 @@
 #include <pthread.h>
 
 #if HAVE_GCRYPT_H
-#if defined __APPLE__
+#if defined __APPLE__ || defined(__sun)
 /* default xcode compiler throws warnings even when deprecated functionality
  * is not used. -Werror breaks the build because of erroneous warnings.
  * http://stackoverflow.com/questions/10556299/compiler-warnings-with-libgcrypt-v1-5-0/12830209#12830209
@@ -54,7 +54,7 @@
  */
 #define GCRYPT_NO_DEPRECATED
 #include <gcrypt.h>
-#if defined __APPLE__
+#if defined __APPLE__ || defined(__sun)
 /* Re enable deprecation warnings */
 #pragma GCC diagnostic warning "-Wdeprecated-declarations"
 #endif
