$NetBSD: patch-xen_arch_x86_time.c,v 1.3 2015/12/29 04:04:32 dholland Exp $

--- xen/arch/x86/time.c.orig	2013-09-10 06:42:18.000000000 +0000
+++ xen/arch/x86/time.c	2013-09-11 14:30:13.000000000 +0000
@@ -105,7 +105,7 @@
 {
     u32 product_int, product_frac;
     asm (
-        "mul %3"
+        "mull %3"
         : "=a" (product_frac), "=d" (product_int)
         : "0" (multiplicand), "r" (multiplier) );
     return product_int;
@@ -129,10 +129,10 @@
 
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
