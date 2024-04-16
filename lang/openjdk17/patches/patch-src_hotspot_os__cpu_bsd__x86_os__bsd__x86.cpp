$NetBSD: patch-src_hotspot_os__cpu_bsd__x86_os__bsd__x86.cpp,v 1.1 2024/04/16 16:14:38 tsutsui Exp $

- Fix a build error on NetBSD/i386 10.0, per old upstream implementation:
 https://github.com/battleblow/jdk17u/commit/fb74640#diff-8c61a4cafafa5e629be7eac3205bb72dba3b53e720bd5052ed72c66bbe79e71c

> src/hotspot/os_cpu/bsd_x86/os_bsd_x86.cpp:288:37: error: attributes are not allowed on a function-definition
>   288 | address os::current_stack_pointer() __attribute__ ((optnone)) {
>       |                                     ^~~~~~~~~~~~~

--- src/hotspot/os_cpu/bsd_x86/os_bsd_x86.cpp.orig	2024-02-04 02:18:56.000000000 +0000
+++ src/hotspot/os_cpu/bsd_x86/os_bsd_x86.cpp
@@ -285,11 +285,18 @@ address os::current_stack_pointer() {
   return (address)__builtin_frame_address(0);
 }
 #else
+#if defined(__clang__) || defined(__llvm__)
 address os::current_stack_pointer() __attribute__ ((optnone)) {
   intptr_t* esp;
   __asm__ __volatile__ ("mov %%" SPELL_REG_SP ", %0":"=r"(esp):);
   return (address) esp;
 }
+#else
+address os::current_stack_pointer() {
+  register void *esp __asm__ (SPELL_REG_SP);
+  return (address) esp;
+}
+#endif
 #endif
 
 char* os::non_memory_address_word() {
