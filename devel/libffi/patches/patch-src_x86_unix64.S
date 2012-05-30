$NetBSD: patch-src_x86_unix64.S,v 1.1 2012/05/30 09:13:16 jperkin Exp $

Apply fix from http://gcc.gnu.org/ml/java-patches/2010-q1/msg00058.html

--- src/x86/unix64.S.orig	Wed May 30 08:50:05 2012
+++ src/x86/unix64.S	Wed May 30 08:50:41 2012
@@ -324,7 +324,11 @@
 .LUW9:
 	.size	ffi_closure_unix64,.-ffi_closure_unix64
 
+#ifdef HAVE_AS_X86_64_UNWIND_SECTION_TYPE
+	.section	.eh_frame,"a",@unwind
+#else
 	.section	.eh_frame,"a",@progbits
+#endif
 .Lframe1:
 	.long	.LECIE1-.LSCIE1		/* CIE Length */
 .LSCIE1:
