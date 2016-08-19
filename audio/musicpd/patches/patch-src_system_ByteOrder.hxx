$NetBSD: patch-src_system_ByteOrder.hxx,v 1.6 2016/08/19 13:52:39 wiz Exp $

also look in <machine/endian.h> on netbsd for endian info (fixes
non x86, mipsel and armel builds.)
https://bugs.musicpd.org/view.php?id=4569

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
