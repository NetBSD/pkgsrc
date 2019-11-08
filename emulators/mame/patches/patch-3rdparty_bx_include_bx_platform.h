$NetBSD: patch-3rdparty_bx_include_bx_platform.h,v 1.8 2019/11/08 09:44:17 wiz Exp $

Improve NetBSD support.
https://github.com/bkaradzic/bx/pull/219

--- 3rdparty/bx/include/bx/platform.h.orig	2019-10-29 17:16:37.000000000 +0000
+++ 3rdparty/bx/include/bx/platform.h
@@ -35,6 +35,7 @@
 #define BX_CRT_MINGW  0
 #define BX_CRT_MSVC   0
 #define BX_CRT_NEWLIB 0
+#define BX_CRT_BSD    0
 
 #ifndef BX_CRT_MUSL
 #	define BX_CRT_MUSL 0
@@ -242,6 +243,9 @@
 #	elif defined(__apple_build_version__) || defined(__ORBIS__) || defined(__EMSCRIPTEN__) || defined(__llvm__) || defined(__HAIKU__)
 #		undef  BX_CRT_LIBCXX
 #		define BX_CRT_LIBCXX 1
+#	elif BX_PLATFORM_BSD
+#		undef  BX_CRT_BSD
+#		define BX_CRT_BSD 1
 #	endif //
 
 #	if !BX_CRT_BIONIC \
@@ -250,7 +254,8 @@
 	&& !BX_CRT_MINGW  \
 	&& !BX_CRT_MSVC   \
 	&& !BX_CRT_MUSL   \
-	&& !BX_CRT_NEWLIB
+	&& !BX_CRT_NEWLIB \
+	&& !BX_CRT_BSD
 #		undef  BX_CRT_NONE
 #		define BX_CRT_NONE 1
 #	endif // BX_CRT_*
@@ -425,6 +430,8 @@
 #	define BX_CRT_NAME "Newlib"
 #elif BX_CRT_MUSL
 #	define BX_CRT_NAME "musl libc"
+#elif BX_CRT_BSD
+#	define BX_CRT_NAME "BSD"
 #elif BX_CRT_NONE
 #	define BX_CRT_NAME "None"
 #else
