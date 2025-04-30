$NetBSD: patch-scripts_src_3rdparty.lua,v 1.8 2025/04/30 15:50:53 wiz Exp $

NetBSD has arc4random too.

Disable SSE usage in bimg - it seems to assume availability of AVX2
intrinsics?

Compiling 3rdparty/bimg/3rdparty/astc-encoder/source/astcenc_decompress_symbolic.cpp...
In file included from /usr/pkg/gcc8/lib/gcc/x86_64--netbsd/8.5.0/include/immintrin.h:35,
                 from ../../../../../3rdparty/bimg/3rdparty/astc-encoder/source/astcenc_mathlib.h:85,
                 from ../../../../../3rdparty/bimg/3rdparty/astc-encoder/source/astcenc_internal.h:34,
                 from ../../../../../3rdparty/bimg/3rdparty/astc-encoder/source/astcenc_decompress_symbolic.cpp:22:
/usr/pkg/gcc8/lib/gcc/x86_64--netbsd/8.5.0/include/tmmintrin.h: In function 'vint4 vtable_8bt_32bi(vint4, vint4, vint4)':
/usr/pkg/gcc8/lib/gcc/x86_64--netbsd/8.5.0/include/tmmintrin.h:136:1: error: inlining failed in call to always_inline '__m128i _mm_shuffle_epi8(__m128i, __m128i)': target specific option mismatch

--- scripts/src/3rdparty.lua.orig	2025-04-29 07:11:59.000000000 +0000
+++ scripts/src/3rdparty.lua
@@ -57,7 +57,7 @@ if _OPTIONS["targetos"]=="windows" then
 		"__USE_MINGW_ANSI_STDIO=0",
 	}
 end
-if _OPTIONS["targetos"]=="macosx" or _OPTIONS["targetos"]=="freebsd" then
+if _OPTIONS["targetos"]=="macosx" or _OPTIONS["targetos"]=="freebsd" or _OPTIONS["targetos"]=="netbsd" then
 	defines {
 		"HAVE_ARC4RANDOM",
 	}
@@ -1410,7 +1410,7 @@ project "bimg"
 		configuration { "x64", "mingw*", "not arm64" }
 			defines {
 				"ASTCENC_AVX=0",
-				"ASTCENC_SSE=" .. ssever,
+				"ASTCENC_SSE=0"
 			}
 		configuration { }
 	end
