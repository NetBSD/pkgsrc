$NetBSD: patch-src_mapi_entry__x86__tls.h,v 1.6 2020/03/08 10:35:03 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

--- src/mapi/entry_x86_tls.h.orig	2020-03-05 21:34:32.000000000 +0000
+++ src/mapi/entry_x86_tls.h
@@ -45,6 +45,25 @@ __asm__("x86_current_tls:\n\t"
 	"movl " ENTRY_CURRENT_TABLE "@GOTNTPOFF(%eax), %eax\n\t"
 	"ret");
 
+#if defined(__NetBSD__)
+__asm__("x86_current_table_helper:\n\t"
+	"call 1f\n\t"
+	"1:\n\t"
+	"popl %eax\n\t"
+	"addl $_GLOBAL_OFFSET_TABLE_+[.-1b], %eax\n\t"
+	"movl " ENTRY_CURRENT_TABLE "@GOTNTPOFF(%eax), %eax\n\t"
+	"movl %gs:(%eax), %eax\n\t"
+	"testl %eax, %eax\n\t"
+	"je 2f\n\t"
+	"ret\n\t"
+	"2:\n\t"
+	"call 3f\n\t"
+	"3:\n\t"
+	"popl %eax\n\t"
+	"addl $_GLOBAL_OFFSET_TABLE_+[.-3b], %eax\n\t"
+	"jmp *" ENTRY_CURRENT_TABLE_GET "@GOT(%eax)");
+#endif
+
 #ifndef GLX_X86_READONLY_TEXT
 __asm__(".section wtext, \"awx\", @progbits");
 #endif /* GLX_X86_READONLY_TEXT */
@@ -58,6 +77,11 @@ __asm__(".balign 16\n"
    ".balign 16\n"                \
    func ":"
 
+#if defined(__NetBSD__)
+#define STUB_ASM_CODE(slot)                                 \
+   "call x86_current_table_helper\n\t"                      \
+   "jmp *(4 * " slot ")(%eax)"
+#else
 #define STUB_ASM_CODE(slot)                                 \
    "call 1f\n"                                              \
    "1:\n\t"                                                 \
@@ -66,6 +90,7 @@ __asm__(".balign 16\n"
    "movl " ENTRY_CURRENT_TABLE "@GOTNTPOFF(%eax), %eax\n\t" \
    "movl %gs:(%eax), %eax\n\t"                              \
    "jmp *(4 * " slot ")(%eax)"
+#endif
 
 #define MAPI_TMP_STUB_ASM_GCC
 #include "mapi_tmp.h"
