$NetBSD: patch-src_mapi_entry__x86-64__tls.h,v 1.2 2015/09/26 08:45:02 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

Fix --enable-glx-tls with clang. From FreeBSD.

--- src/mapi/entry_x86-64_tls.h.orig	2015-09-11 17:41:47.000000000 +0000
+++ src/mapi/entry_x86-64_tls.h
@@ -36,10 +36,19 @@ __asm__(".text\n"
    ".balign 32\n"                                        \
    func ":"
 
+#ifdef __NetBSD__
 #define STUB_ASM_CODE(slot)                              \
    "movq " ENTRY_CURRENT_TABLE "@GOTTPOFF(%rip), %rax\n\t"  \
    "movq %fs:(%rax), %r11\n\t"                           \
+   "testq %r11, %r11\n\t"                                \
+   "cmoveq table_noop_array@GOTPCREL(%rip), %r11\n\t"    \
    "jmp *(8 * " slot ")(%r11)"
+#else
+#define STUB_ASM_CODE(slot)                              \
+   "movq " ENTRY_CURRENT_TABLE "@GOTTPOFF(%rip), %rax\n\t"  \
+   "movq %fs:(%rax), %r11\n\t"                           \
+   "jmp *(8 * " slot ")(%r11)"
+#endif
 
 #define MAPI_TMP_STUB_ASM_GCC
 #include "mapi_tmp.h"
@@ -61,8 +70,8 @@ entry_patch_public(void)
 {
 }
 
-static char
-x86_64_entry_start[];
+extern char
+x86_64_entry_start[] __attribute__((visibility("hidden")));
 
 mapi_func
 entry_get_public(int slot)
