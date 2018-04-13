$NetBSD: patch-libmariadb_ma__context.c,v 1.1 2018/04/13 08:04:14 fhajny Exp $

Fix incorrect assembler syntax.

--- libmariadb/ma_context.c.orig	2018-01-17 11:43:58.000000000 +0000
+++ libmariadb/ma_context.c
@@ -200,6 +200,7 @@ my_context_spawn(struct my_context *c, v
   */
   __asm__ __volatile__
     (
+     ".cfi_startproc\n\t"
      "movq %%rsp, (%[save])\n\t"
      "movq %[stack], %%rsp\n\t"
 #if __GNUC__ >= 4 && __GNUC_MINOR__ >= 4 && !defined(__INTEL_COMPILER)
@@ -240,6 +241,7 @@ my_context_spawn(struct my_context *c, v
      "2:\n\t"
      "movl $1, %[ret]\n"
      "3:\n"
+     ".cfi_endproc\n"
      : [ret] "=a" (ret),
        [f] "+S" (f),
        /* Need this in %rdi to follow calling convention. */
@@ -260,6 +262,7 @@ my_context_continue(struct my_context *c
 
   __asm__ __volatile__
     (
+     ".cfi_startproc\n\t"
      "movq (%[save]), %%rax\n\t"
      "movq %%rsp, (%[save])\n\t"
      "movq %%rax, %%rsp\n\t"
@@ -309,6 +312,7 @@ my_context_continue(struct my_context *c
      "2:\n\t"
      "movl $1, %[ret]\n"
      "3:\n"
+     ".cfi_endproc\n"
      : [ret] "=a" (ret)
      : /* Need this in callee-save register to preserve in function call. */
        [save] "b" (&c->save[0])
@@ -324,6 +328,7 @@ my_context_yield(struct my_context *c)
   uint64_t *save= &c->save[0];
   __asm__ __volatile__
     (
+     ".cfi_startproc\n\t"
      "movq (%[save]), %%rax\n\t"
      "movq %%rsp, (%[save])\n\t"
      "movq %%rax, %%rsp\n\t"
@@ -352,6 +357,7 @@ my_context_yield(struct my_context *c)
      "jmpq *%%rax\n"
 
      "1:\n"
+     ".cfi_endproc\n"
      : [save] "+D" (save)
      :
      : "rax", "rcx", "rdx", "rsi", "r8", "r9", "r10", "r11", "memory", "cc"
@@ -439,6 +445,7 @@ my_context_spawn(struct my_context *c, v
   */
   __asm__ __volatile__
     (
+     ".cfi_startproc\n\t"
      "movl %%esp, (%[save])\n\t"
      "movl %[stack], %%esp\n\t"
 #if __GNUC__ >= 4 && __GNUC_MINOR__ >= 4 && !defined(__INTEL_COMPILER)
@@ -479,6 +486,7 @@ my_context_spawn(struct my_context *c, v
      "3:\n\t"
      "movl $1, %[ret]\n"
      "4:\n"
+     ".cfi_endproc\n"
      : [ret] "=a" (ret),
        [f] "+c" (f),
        [d] "+d" (d)
@@ -498,6 +506,7 @@ my_context_continue(struct my_context *c
 
   __asm__ __volatile__
     (
+     ".cfi_startproc\n\t"
      "movl (%[save]), %%eax\n\t"
      "movl %%esp, (%[save])\n\t"
      "movl %%eax, %%esp\n\t"
@@ -543,6 +552,7 @@ my_context_continue(struct my_context *c
      "3:\n\t"
      "movl $1, %[ret]\n"
      "4:\n"
+     ".cfi_endproc\n"
      : [ret] "=a" (ret)
      : /* Need this in callee-save register to preserve in function call. */
        [save] "D" (&c->save[0])
@@ -558,6 +568,7 @@ my_context_yield(struct my_context *c)
   uint64_t *save= &c->save[0];
   __asm__ __volatile__
     (
+     ".cfi_startproc\n\t"
      "movl (%[save]), %%eax\n\t"
      "movl %%esp, (%[save])\n\t"
      "movl %%eax, %%esp\n\t"
@@ -584,6 +595,7 @@ my_context_yield(struct my_context *c)
      "jmp *%%eax\n"
 
      "2:\n"
+     ".cfi_endproc\n"
      : [save] "+d" (save)
      :
      : "eax", "ecx", "memory", "cc"
