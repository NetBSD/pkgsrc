$NetBSD: patch-mysys_my__context.c,v 1.1 2021/05/23 15:32:47 nia Exp $

Don't insert DWARF directives on SunOS.

--- mysys/my_context.c.orig	2020-03-25 10:28:39.248862779 +0000
+++ mysys/my_context.c
@@ -207,7 +207,7 @@ my_context_spawn(struct my_context *c, v
      "movq %%rsp, (%[save])\n\t"
      "movq %[stack], %%rsp\n\t"
 #if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 4) || __clang__) && \
-     !defined(__INTEL_COMPILER)
+     !defined(__INTEL_COMPILER) && !defined(__sun)
      /*
        This emits a DWARF DW_CFA_undefined directive to make the return address
        undefined. This indicates that this is the top of the stack frame, and
@@ -455,7 +455,7 @@ my_context_spawn(struct my_context *c, v
     (
      "movl %%esp, (%[save])\n\t"
      "movl %[stack], %%esp\n\t"
-#if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 4)) && !defined(__INTEL_COMPILER)
+#if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 4)) && !defined(__INTEL_COMPILER) && !defined(__sun)
      /*
        This emits a DWARF DW_CFA_undefined directive to make the return address
        undefined. This indicates that this is the top of the stack frame, and
