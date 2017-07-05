$NetBSD: patch-pngpriv.h,v 1.1 2017/07/05 04:59:16 maya Exp $

Don't typedef types when included by assembler files

--- pngpriv.h.orig	2017-06-28 18:46:03.000000000 +0000
+++ pngpriv.h
@@ -464,7 +464,7 @@
    static_cast<type>(static_cast<void*>(value))
 #  define png_aligncastconst(type, value) \
    static_cast<type>(static_cast<const void*>(value))
-#else
+#elif !defined(__ASSEMBLER__)
 #  define png_voidcast(type, value) (value)
 #  ifdef _WIN64
 #     ifdef __GNUC__
