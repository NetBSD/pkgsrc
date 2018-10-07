$NetBSD: patch-src_mapi_entry__x86-64__tls.h,v 1.1 2018/10/07 23:49:31 ryoon Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

Fix --enable-glx-tls with clang. From FreeBSD.

table_noop_array is only defined for shared-glapi.
es1api and es2api are not going to be patched for NetBSD.

--- src/mapi/entry_x86-64_tls.h.orig	2017-11-20 14:25:47.000000000 +0000
+++ src/mapi/entry_x86-64_tls.h
@@ -43,10 +43,19 @@ __asm__(".text\n"
 
 #ifndef __ILP32__
 
+#if defined(__NetBSD__) && defined(MAPI_MODE_GLAPI)
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
 
 #else
 
