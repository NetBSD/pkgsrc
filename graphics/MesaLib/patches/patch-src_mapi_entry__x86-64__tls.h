$NetBSD: patch-src_mapi_entry__x86-64__tls.h,v 1.4 2020/02/19 21:03:41 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

table_noop_array is only defined for shared-glapi.
es1api and es2api are not going to be patched for NetBSD.

--- src/mapi/entry_x86-64_tls.h.orig	2019-12-04 22:10:14.000000000 +0000
+++ src/mapi/entry_x86-64_tls.h
@@ -32,13 +32,13 @@
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
@@ -46,7 +46,12 @@ __asm__(".text\n"
 #define STUB_ASM_CODE(slot)                              \
    "movq " ENTRY_CURRENT_TABLE "@GOTTPOFF(%rip), %rax\n\t"  \
    "movq %fs:(%rax), %r11\n\t"                           \
-   "jmp *(8 * " slot ")(%r11)"
+   "testq %r11, %r11\n\t"                                \
+   "je 1f\n\t"                                           \
+   "jmp *(8 * " slot ")(%r11)\n\t"                       \
+   "1:\n\t"                                              \
+   "call " ENTRY_CURRENT_TABLE_GET "\n\t"                \
+   "jmp *(8 * " slot ")(%rax)"
 
 #else
 
@@ -77,7 +82,7 @@ x86_64_entry_start[] HIDDEN;
 mapi_func
 entry_get_public(int slot)
 {
-   return (mapi_func) (x86_64_entry_start + slot * 32);
+   return (mapi_func) (x86_64_entry_start + slot * 64);
 }
 
 void
