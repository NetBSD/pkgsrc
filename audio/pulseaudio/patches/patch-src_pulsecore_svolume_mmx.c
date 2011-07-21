$NetBSD: patch-src_pulsecore_svolume_mmx.c,v 1.1 2011/07/21 15:10:11 joerg Exp $

Drop lvalue casts in assembler constraints as clang rejects those.

--- src/pulsecore/svolume_mmx.c.orig	2011-07-20 12:49:46.000000000 +0000
+++ src/pulsecore/svolume_mmx.c
@@ -153,7 +153,7 @@ pa_volume_s16ne_mmx (int16_t *samples, i
         "6:                             \n\t"
         " emms                          \n\t"
 
-        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" ((pa_reg_x86)channel), "=&r" (temp)
+        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
         : "rm" ((pa_reg_x86)channels)
         : "cc"
     );
@@ -229,7 +229,7 @@ pa_volume_s16re_mmx (int16_t *samples, i
         "6:                             \n\t"
         " emms                          \n\t"
 
-        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" ((pa_reg_x86)channel), "=&r" (temp)
+        : "+r" (samples), "+r" (volumes), "+r" (length), "=D" (channel), "=&r" (temp)
         : "rm" ((pa_reg_x86)channels)
         : "cc"
     );
