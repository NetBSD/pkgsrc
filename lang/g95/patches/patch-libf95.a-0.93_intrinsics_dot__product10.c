$NetBSD: patch-libf95.a-0.93_intrinsics_dot__product10.c,v 1.2 2015/12/29 23:34:46 dholland Exp $

Fix assembler instructions.

--- libf95.a-0.93/intrinsics/dot_product10.c.orig	2013-03-01 11:13:24.000000000 +0000
+++ libf95.a-0.93/intrinsics/dot_product10.c
@@ -225,7 +225,7 @@ char *ap, *bp;
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "movsbl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (bp), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (bp), "m" (temp) : EAX
 
 #include "dot_product10.c"
 
@@ -237,7 +237,7 @@ char *ap, *bp;
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "movswl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (bp), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (bp), "m" (temp) : EAX
 
 #include "dot_product10.c"
 
@@ -247,7 +247,7 @@ char *ap, *bp;
                  "fldt ( %" EAX ")\n" : : "m" (ap) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
-                 "fild ( %" EAX ")\n" : : "m" (bp), "m" (temp) : EAX
+                 "filds ( %" EAX ")\n" : : "m" (bp), "m" (temp) : EAX
 
 #include "dot_product10.c"
 
@@ -286,7 +286,7 @@ char *ap, *bp;
 #define LOAD_A   "mov %0, %" EAX "\n" \
                  "movsbl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (ap), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (ap), "m" (temp) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "fldt ( %" EAX ")\n" : : "m" (bp) : EAX
@@ -299,7 +299,7 @@ char *ap, *bp;
 #define LOAD_A   "mov %0, %" EAX "\n" \
                  "movswl (%" EAX "), %%eax\n" \
                  "mov %%eax, %1\n" \
-                 "fild %1\n" : : "m" (ap), "m" (temp) : EAX
+                 "filds %1\n" : : "m" (ap), "m" (temp) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "fldt ( %" EAX ")\n" : : "m" (bp) : EAX
@@ -309,7 +309,7 @@ char *ap, *bp;
 #define SUBROUTINE     prefix(dot_product_i4_r10)
 
 #define LOAD_A   "mov %0, %" EAX "\n" \
-                 "fild ( %" EAX ")\n" : : "m" (ap), "m" (temp) : EAX
+                 "filds ( %" EAX ")\n" : : "m" (ap), "m" (temp) : EAX
 
 #define LOAD_B   "mov %0, %" EAX "\n" \
                  "fldt ( %" EAX ")\n" : : "m" (bp) : EAX
