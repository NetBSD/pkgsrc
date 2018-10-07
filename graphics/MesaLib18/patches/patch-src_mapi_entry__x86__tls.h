$NetBSD: patch-src_mapi_entry__x86__tls.h,v 1.1 2018/10/07 23:49:31 ryoon Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

Fix --enable-glx-tls with clang. From FreeBSD.

table_noop_array is only defined for shared-glapi.
es1api and es2api are not going to be patched for NetBSD.

--- src/mapi/entry_x86_tls.h.orig	2018-01-18 21:30:29.000000000 +0000
+++ src/mapi/entry_x86_tls.h
@@ -56,10 +56,27 @@ __asm__(".balign 16\n"
    ".balign 16\n"                \
    func ":"
 
+#if defined(__NetBSD__) && defined(MAPI_MODE_GLAPI)
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
