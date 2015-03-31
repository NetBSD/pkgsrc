$NetBSD: patch-libretro_libco_armeabi.c,v 1.1 2015/03/31 15:24:14 joerg Exp $

--- libretro/libco/armeabi.c.orig	2015-03-30 10:10:39.000000000 +0000
+++ libretro/libco/armeabi.c
@@ -22,19 +22,15 @@ extern "C" {
 static thread_local uint32_t co_active_buffer[64];
 static thread_local cothread_t co_active_handle;
 
-asm (
+/* ASM */
+__attribute__((naked))
+void co_switch_arm(cothread_t handle, cothread_t current)  {
+  asm volatile (
       ".arm\n"
-      ".align 4\n"
-      ".globl co_switch_arm\n"
-      ".globl _co_switch_arm\n"
-      "co_switch_arm:\n"
-      "_co_switch_arm:\n"      
       "  stmia r1!, {r4, r5, r6, r7, r8, r9, r10, r11, sp, lr}\n"
       "  ldmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11, sp, pc}\n"
-    );
-
-/* ASM */
-void co_switch_arm(cothread_t handle, cothread_t current);
+  );
+}
 
 static void crash(void)
 {
