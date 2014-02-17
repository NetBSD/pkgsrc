$NetBSD: patch-src_network.c,v 1.1 2014/02/17 11:21:55 fhajny Exp $

Need the workaround on at least SunOS too.
--- src/network.c.orig	2014-01-26 08:09:23.532559941 +0000
+++ src/network.c
@@ -59,7 +59,7 @@
 
 #if HAVE_LIBGCRYPT
 # include <pthread.h>
-# if defined __APPLE__
+# if defined(__APPLE__) || defined(__sun)
 /* default xcode compiler throws warnings even when deprecated functionality
  * is not used. -Werror breaks the build because of erroneous warnings.
  * http://stackoverflow.com/questions/10556299/compiler-warnings-with-libgcrypt-v1-5-0/12830209#12830209
@@ -72,7 +72,7 @@
  */
 # define GCRYPT_NO_DEPRECATED
 # include <gcrypt.h>
-# if defined __APPLE__
+# if defined(__APPLE__) || defined(__sun)
 /* Re enable deprecation warnings */
 #  pragma GCC diagnostic warning "-Wdeprecated-declarations"
 # endif
