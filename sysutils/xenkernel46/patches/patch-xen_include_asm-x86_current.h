$NetBSD: patch-xen_include_asm-x86_current.h,v 1.1.1.1 2016/07/04 07:25:13 jnemeth Exp $

--- xen/include/asm-x86/current.h.orig	2015-01-30 12:45:05.000000000 +0000
+++ xen/include/asm-x86/current.h
@@ -25,7 +25,7 @@ struct cpu_info {
 
 static inline struct cpu_info *get_cpu_info(void)
 {
-    register unsigned long sp asm("rsp");
+    unsigned long sp = (unsigned long)__builtin_frame_address(0);
 
     return (struct cpu_info *)((sp & ~(STACK_SIZE-1)) + STACK_SIZE) - 1;
 }
