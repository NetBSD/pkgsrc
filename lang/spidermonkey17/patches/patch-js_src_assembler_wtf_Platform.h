$NetBSD: patch-js_src_assembler_wtf_Platform.h,v 1.1 2016/10/03 02:46:47 maya Exp $

don't error out for other MIPS ABIs.

--- js/src/assembler/wtf/Platform.h.orig	2013-02-11 22:33:22.000000000 +0000
+++ js/src/assembler/wtf/Platform.h
@@ -139,8 +139,7 @@
 
 /* WTF_CPU_MIPS - MIPS 32-bit */
 /* Note: Only O32 ABI is tested, so we enable it for O32 ABI for now.  */
-#if (defined(mips) || defined(__mips__) || defined(MIPS) || defined(_MIPS_)) \
-    && defined(_ABIO32)
+#if (defined(mips) || defined(__mips__) || defined(MIPS) || defined(_MIPS_))
 #define WTF_CPU_MIPS 1
 #if defined(__MIPSEB__)
 #define WTF_CPU_BIG_ENDIAN 1
