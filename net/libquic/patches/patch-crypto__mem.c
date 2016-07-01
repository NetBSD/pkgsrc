$NetBSD: patch-crypto__mem.c,v 1.1 2016/07/01 20:32:35 agc Exp $

NetBSD portability patches

--- boringssl/crypto/mem.c.orig	2015-12-30 15:55:51.000000000 -0800
+++ boringssl/crypto/mem.c	2015-12-30 18:06:05.000000000 -0800
@@ -55,7 +55,9 @@
  * [including the GNU Public Licence.] */
 
 #if !defined(_POSIX_C_SOURCE)
+#  if !defined(__NetBSD__)
 #define _POSIX_C_SOURCE 201410L  /* needed for strdup, snprintf, vprintf etc */
+#  endif
 #endif
 
 #include <openssl/mem.h>
