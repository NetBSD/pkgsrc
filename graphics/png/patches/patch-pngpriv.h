$NetBSD: patch-pngpriv.h,v 1.2 2022/09/26 17:08:37 adam Exp $

Don't typedef types when included by assembler files

--- pngpriv.h.orig	2022-09-26 17:03:37.000000000 +0000
+++ pngpriv.h
@@ -496,7 +496,7 @@
    static_cast<type>(static_cast<void*>(value))
 #  define png_aligncastconst(type, value) \
    static_cast<type>(static_cast<const void*>(value))
-#else
+#elif !defined(__ASSEMBLER__)
 #  define png_voidcast(type, value) (value)
 #  define png_constcast(type, value) ((type)(void*)(const void*)(value))
 #  define png_aligncast(type, value) ((void*)(value))
