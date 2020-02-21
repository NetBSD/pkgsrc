$NetBSD: patch-src_mapi_entry__x86-64__tls.h,v 1.5 2020/02/21 21:52:24 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

table_noop_array is only defined for shared-glapi.
es1api and es2api are not going to be patched for NetBSD.

--- src/mapi/entry_x86-64_tls.h.orig	2019-12-04 22:10:14.000000000 +0000
+++ src/mapi/entry_x86-64_tls.h
@@ -32,21 +32,33 @@
 #endif
 
 __asm__(".text\n"
-        ".balign 32\n"
+        ".balign 64\n"
         "x86_64_entry_start:");
 
 #define STUB_ASM_ENTRY(func)                             \
    ".globl " func "\n"                                   \
    ".type " func ", @function\n"                         \
-   ".balign 32\n"                                        \
+   ".balign 64\n"                                        \
    func ":"
 
 #ifndef __ILP32__
 
+#if defined(__NetBSD__)
+#define STUB_ASM_CODE(slot)                              \
+   "movq " ENTRY_CURRENT_TABLE "@GOTTPOFF(%rip), %rax\n\t"  \
+   "movq %fs:(%rax), %r11\n\t"                           \
+   "testq %r11, %r11\n\t"                                \
+   "je 1f\n\t"                                           \
+   "jmp *(8 * " slot ")(%r11)\n\t"                       \
+   "1:\n\t"                                              \
+   "callq " ENTRY_CURRENT_TABLE_GET "@PLT\n\t"           \
+   "jmp *(8 * " slot ")(%rax)"
+#else
 #define STUB_ASM_CODE(slot)                              \
    "movq " ENTRY_CURRENT_TABLE "@GOTTPOFF(%rip), %rax\n\t"  \
    "movq %fs:(%rax), %r11\n\t"                           \
    "jmp *(8 * " slot ")(%r11)"
+#endif
 
 #else
 
@@ -77,7 +89,7 @@ x86_64_entry_start[] HIDDEN;
 mapi_func
 entry_get_public(int slot)
 {
-   return (mapi_func) (x86_64_entry_start + slot * 32);
+   return (mapi_func) (x86_64_entry_start + slot * 64);
 }
 
 void
