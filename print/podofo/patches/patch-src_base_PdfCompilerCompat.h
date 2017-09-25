$NetBSD: patch-src_base_PdfCompilerCompat.h,v 1.3 2017/09/25 22:26:27 joerg Exp $

Ensure alloca exists, even in standard modes on NetBSD.

Merge r1825.

--- src/base/PdfCompilerCompat.h.orig	2017-01-11 20:32:50.000000000 +0000
+++ src/base/PdfCompilerCompat.h
@@ -74,6 +74,9 @@
 #if defined(_WIN32)
 #include <malloc.h>
 #endif
+#ifdef __NetBSD__
+#define	alloca	__builtin_alloca
+#endif
 
 // Disable usage of min() and max() macros 
 #if defined(_WIN32) && !defined(__MINGW32__)
@@ -198,16 +201,6 @@ namespace PoDoFo {
 
 #endif // defined(_WIN32)
 
-// Visual C++ 2015 (_MSC_VER 1900) still uses __cplusplus = 199711 so, we need both tests
-// this shrinks enum types from sizeof(int) to sizeof(char) which creates significant
-// space savings on PdfObject / PdfVariant
-#if (defined(_MSC_VER) && _MSC_VER < 1900) || (!defined(_MSC_VER) &&  __cplusplus < 201103)
-#define PODOFO_ENUM_UINT8
-#else 
-#define PODOFO_ENUM_UINT8	: uint8_t
-#endif 
-
-
 /**
  * \page PoDoFo PdfCompilerCompat Header
  * 
