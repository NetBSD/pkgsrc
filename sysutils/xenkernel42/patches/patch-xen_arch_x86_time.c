$NetBSD: patch-xen_arch_x86_time.c,v 1.1 2013/06/13 21:49:59 joerg Exp $

--- xen/arch/x86/time.c.orig	2013-04-23 16:42:55.000000000 +0000
+++ xen/arch/x86/time.c
@@ -107,7 +107,7 @@ static inline u32 mul_frac(u32 multiplic
 {
     u32 product_int, product_frac;
     asm (
-        "mul %3"
+        "mull %3"
         : "=a" (product_frac), "=d" (product_int)
         : "0" (multiplicand), "r" (multiplier) );
     return product_int;
@@ -131,10 +131,10 @@ static inline u64 scale_delta(u64 delta,
 
 #ifdef CONFIG_X86_32
     asm (
-        "mul  %5       ; "
+        "mull  %5       ; "
         "mov  %4,%%eax ; "
         "mov  %%edx,%4 ; "
-        "mul  %5       ; "
+        "mull  %5       ; "
         "xor  %5,%5    ; "
         "add  %4,%%eax ; "
         "adc  %5,%%edx ; "
@@ -142,7 +142,7 @@ static inline u64 scale_delta(u64 delta,
         : "a" ((u32)delta), "1" ((u32)(delta >> 32)), "2" (scale->mul_frac) );
 #else
     asm (
-        "mul %2 ; shrd $32,%1,%0"
+        "mulq %2 ; shrd $32,%1,%0"
         : "=a" (product), "=d" (delta)
         : "rm" (delta), "0" ((u64)scale->mul_frac) );
 #endif
