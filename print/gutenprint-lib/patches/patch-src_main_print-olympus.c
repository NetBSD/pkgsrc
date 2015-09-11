$NetBSD: patch-src_main_print-olympus.c,v 1.1 2015/09/11 12:50:34 gdt Exp $

Fix endian detection to be like other uses in gutenprint.
Reported upstream 20150909.

--- src/main/print-olympus.c.orig	2014-05-15 01:18:36.000000000 +0000
+++ src/main/print-olympus.c
@@ -4901,9 +4901,9 @@ dyesub_do_print(stp_vars_t *v, stp_image
   }
 
   if (pv.bytes_per_ink_channel > 1) {
-#if defined(__LITTLE_ENDIAN) || defined(__LITTLE_ENDIAN__)
+#if __BYTE_ORDER == __LITTLE_ENDIAN
     pv.byteswap = dyesub_feature(caps, DYESUB_FEATURE_BIGENDIAN);
-#elif defined (__BIG_ENDIAN) || defined(__BIG_ENDIAN__)
+#elif __BYTE_ORDER == __BIG_ENDIAN
     pv.byteswap = !dyesub_feature(caps, DYESUB_FEATURE_BIGENDIAN);
 #else
 #error "Unable to determine endianness, aborting compilation!"
