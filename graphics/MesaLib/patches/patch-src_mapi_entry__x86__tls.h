$NetBSD: patch-src_mapi_entry__x86__tls.h,v 1.2 2015/09/26 08:45:02 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

Fix --enable-glx-tls with clang. From FreeBSD.

--- src/mapi/entry_x86_tls.h.orig	2015-09-02 17:06:23.000000000 +0000
+++ src/mapi/entry_x86_tls.h
@@ -50,10 +50,27 @@ __asm__(".balign 16\n"
    ".balign 16\n"                \
    func ":"
 
+#ifdef __NetBSD__
+extern const mapi_func table_noop_array[];
 #define STUB_ASM_CODE(slot)      \
    "call x86_current_tls\n\t"    \
    "movl %gs:(%eax), %eax\n\t"   \
+   "testl %eax, %eax\n\t"        \
+   "je 1f\n\t"                   \
+   "jmp *(4 * " slot ")(%eax)\n\t" \
+   "1:\n\t"                      \
+   "call 2f\n"                   \
+   "2:\n\t"                      \
+   "popl %eax\n\t"               \
+   "addl $_GLOBAL_OFFSET_TABLE_+[.-1b], %eax\n\t" \
+   "movl table_noop_array@GOT(%eax), %eax\n\t" \
    "jmp *(4 * " slot ")(%eax)"
+#else
+#define STUB_ASM_CODE(slot)      \
+   "call x86_current_tls\n\t"    \
+   "movl %gs:(%eax), %eax\n\t"   \
+   "jmp *(4 * " slot ")(%eax)"
+#endif
 
 #define MAPI_TMP_STUB_ASM_GCC
 #include "mapi_tmp.h"
@@ -71,8 +88,8 @@ __asm__(".text");
 extern unsigned long
 x86_current_tls();
 
-static char x86_entry_start[];
-static char x86_entry_end[];
+extern char x86_entry_start[] __attribute__((visibility("hidden")));
+extern char x86_entry_end[] __attribute__((visibility("hidden")));
 
 void
 entry_patch_public(void)
