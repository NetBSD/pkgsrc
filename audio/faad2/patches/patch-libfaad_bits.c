$NetBSD: patch-libfaad_bits.c,v 1.1 2019/07/11 09:03:35 nia Exp $

Fix a potential buffer overflow.

Upstream commit:
https://github.com/knik0/faad2/commit/942c3e0aee748ea6fe97cb2c1aa5893225316174.patch

--- libfaad/bits.c.orig	2017-07-06 19:16:40.000000000 +0000
+++ libfaad/bits.c
@@ -167,7 +167,10 @@ void faad_resetbits(bitfile *ld, int bit
     int words = bits >> 5;
     int remainder = bits & 0x1F;
 
-    ld->bytes_left = ld->buffer_size - words*4;
+    if (ld->buffer_size < words * 4)
+        ld->bytes_left = 0;
+    else
+        ld->bytes_left = ld->buffer_size - words*4;
 
     if (ld->bytes_left >= 4)
     {
