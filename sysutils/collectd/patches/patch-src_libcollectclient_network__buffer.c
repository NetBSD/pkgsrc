$NetBSD: patch-src_libcollectclient_network__buffer.c,v 1.2 2016/10/13 15:17:28 fhajny Exp $

Need the workaround on at least SunOS too.
--- src/libcollectdclient/network_buffer.c.orig	2016-09-11 08:10:25.263038721 +0000
+++ src/libcollectdclient/network_buffer.c
@@ -36,7 +36,7 @@
 #include <pthread.h>
 
 #if HAVE_LIBGCRYPT
-# if defined __APPLE__
+# if defined __APPLE__ || defined(__sun)
 /* default xcode compiler throws warnings even when deprecated functionality
  * is not used. -Werror breaks the build because of erroneous warnings.
  * http://stackoverflow.com/questions/10556299/compiler-warnings-with-libgcrypt-v1-5-0/12830209#12830209
@@ -49,7 +49,7 @@
  */
 # define GCRYPT_NO_DEPRECATED
 # include <gcrypt.h>
-# if defined __APPLE__
+# if defined(__APPLE__) || defined(__sun)
 /* Re enable deprecation warnings */
 #  pragma GCC diagnostic warning "-Wdeprecated-declarations"
 # endif
