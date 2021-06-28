$NetBSD: patch-src_hotspot_os__cpu_bsd__arm_bsd__arm__32.s,v 1.1 2021/06/28 22:53:05 tnn Exp $

use gas(1) compatible mmnemonics

--- src/hotspot/os_cpu/bsd_arm/bsd_arm_32.s.orig	2021-06-28 19:59:45.710900666 +0000
+++ src/hotspot/os_cpu/bsd_arm/bsd_arm_32.s
@@ -94,7 +94,7 @@ dw_f2b_loop_32:
         stmia to!, {r3 - r9, ip}
         bgt     dw_f2b_loop_32
 dw_f2b_loop_32_finish:
-        addslt  r2, #32
+        addlts  r2, #32
         beq     disjoint_words_finish
         cmp     r2, #16
 	blt	disjoint_words_small
@@ -142,7 +142,7 @@ cw_f2b_loop_32:
         stmia to!, {r3 - r9, ip}
         bgt     cw_f2b_loop_32
 cw_f2b_loop_32_finish:
-        addslt  r2, #32
+        addlts  r2, #32
         beq     conjoint_words_finish
         cmp     r2, #16
 	blt	conjoint_words_small
@@ -175,7 +175,7 @@ cw_b2f_loop_32:
         stmdb to!, {r3-r9,ip}
         bgt     cw_b2f_loop_32
 cw_b2f_loop_32_finish:
-        addslt  r2, #32
+        addlts  r2, #32
         beq     conjoint_words_finish
         cmp     r2, #16
 	blt	cw_b2f_copy_small
@@ -227,7 +227,7 @@ cs_f2b_loop_32:
         stmia to!, {r3 - r9, ip}
         bgt     cs_f2b_loop_32
 cs_f2b_loop_32_finish:
-        addslt  r2, #32
+        addlts  r2, #32
         beq     conjoint_shorts_finish
         movs    r6, r2, lsr #3
         .align 3
@@ -243,11 +243,11 @@ cs_f2b_4:
         beq     conjoint_shorts_finish
         cmp     r2, #4
         ldrh    r3, [from], #2
-        ldrhge  r4, [from], #2
-        ldrhgt  r5, [from], #2
+        ldrgeh  r4, [from], #2
+        ldrgth  r5, [from], #2
         strh    r3, [to], #2
-        strhge  r4, [to], #2
-        strhgt  r5, [to], #2
+        strgeh  r4, [to], #2
+        strgth  r5, [to], #2
         b       conjoint_shorts_finish
 
 	# Destination not aligned
@@ -305,11 +305,11 @@ cs_f2b_4_u:
         beq     conjoint_shorts_finish
         cmp     r2, #4
         ldrh    r3, [from], #2
-        ldrhge  r4, [from], #2
-        ldrhgt  r5, [from], #2
+        ldrgeh  r4, [from], #2
+        ldrgth  r5, [from], #2
         strh    r3, [to], #2
-        strhge  r4, [to], #2
-        strhgt  r5, [to], #2
+        strgeh  r4, [to], #2
+        strgth  r5, [to], #2
         b       conjoint_shorts_finish
 
 	# Src and dest overlap, copy in a descending order
@@ -332,7 +332,7 @@ cs_b2f_loop_32:
         stmdb to!, {r3-r9,ip}
         bgt     cs_b2f_loop_32
 cs_b2f_loop_32_finish:
-        addslt  r2, #32
+        addlts  r2, #32
         beq     conjoint_shorts_finish
         cmp     r2, #24
         blt     cs_b2f_16
@@ -358,11 +358,11 @@ cs_b2f_8:
 cs_b2f_all_copy:
         cmp     r2, #4
         ldrh    r3, [from, #-2]!
-        ldrhge  r4, [from, #-2]!
-        ldrhgt  r5, [from, #-2]!
+        ldrgeh  r4, [from, #-2]!
+        ldrgth  r5, [from, #-2]!
         strh    r3, [to, #-2]!
-        strhge  r4, [to, #-2]!
-        strhgt  r5, [to, #-2]!
+        strgeh  r4, [to, #-2]!
+        strgth  r5, [to, #-2]!
         b       conjoint_shorts_finish
 
 	# Destination not aligned
@@ -397,7 +397,7 @@ cs_b2f_16_loop_u:
         bgt     cs_b2f_16_loop_u
         beq     conjoint_shorts_finish
 cs_b2f_16_loop_u_finished:
-        addslt  r2, #16
+        addlts  r2, #16
         ldr     r3, [from]
 	cmp     r2, #10
         blt     cs_b2f_2_u_loop
@@ -460,7 +460,7 @@ cl_f2b_loop_32:
         stmia to!, {r3 - r9, ip}
         bgt     cl_f2b_loop_32
 cl_f2b_loop_32_finish:
-        addslt  r2, #32
+        addlts  r2, #32
         beq     conjoint_longs_finish
 conjoint_longs_small:
         cmp     r2, #16
@@ -493,7 +493,7 @@ cl_b2f_loop_32:
         stmdb 	to!, {r3 - r9, ip}
         bgt     cl_b2f_loop_32
 cl_b2f_loop_32_finish:
-        addslt  r2, #32
+        addlts  r2, #32
         beq     conjoint_longs_finish
         cmp     r2, #16
 	blt	cl_b2f_copy_8
