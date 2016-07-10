$NetBSD: patch-src_system_ByteOrder.hxx,v 1.5 2016/07/10 13:38:58 mef Exp $

r 1.1
patches/patch-src_system_ByteOrder.hxx:
  Fix compilation error on Darwin/ppc

r 1.4
also look in <machine/endian.h> on netbsd for endian info (fixes
non x86, mipsel and armel builds.)

--- src/system/ByteOrder.hxx.orig	2014-08-23 05:29:55.000000000 -0700
+++ src/system/ByteOrder.hxx	2015-04-05 16:29:48.000000000 -0700
@@ -40,7 +40,7 @@
 /* well-known big-endian */
 #  define IS_LITTLE_ENDIAN false
 #  define IS_BIG_ENDIAN true
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__NetBSD__)
 /* compile-time check for MacOS */
 #  include <machine/endian.h>
 #  if BYTE_ORDER == LITTLE_ENDIAN
