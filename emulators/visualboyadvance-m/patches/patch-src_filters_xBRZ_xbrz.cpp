$NetBSD: patch-src_filters_xBRZ_xbrz.cpp,v 1.1 2021/05/20 06:45:07 nia Exp $

Remove broken ASM checks.

--- src/filters/xBRZ/xbrz.cpp.orig	2019-10-02 14:17:30.000000000 +0000
+++ src/filters/xBRZ/xbrz.cpp
@@ -66,20 +66,7 @@ uint32_t gradientARGB(uint32_t pixFront,
 
 inline double fastSqrt(double n)
 {
-#ifdef __GNUC__ || __clang__ || __MINGW64_VERSION_MAJOR || __MINGW32_MAJOR_VERSION
-    __asm__ ("fsqrt" : "+t" (n));
-    return n;
-#elif _MSC_VER && _M_IX86
-    // speeds up xBRZ by about 9% compared to std::sqrt which internally uses
-    // the same assembler instructions but adds some "fluff"
-    __asm {
-        fld n
-        fsqrt
-    }
-#else // _MSC_VER && _M_X64 OR other platforms
-    // VisualStudio x86_64 does not allow inline ASM
     return std::sqrt(n);
-#endif
 }
 
 
