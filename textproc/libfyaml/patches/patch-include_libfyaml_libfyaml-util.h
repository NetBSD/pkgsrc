$NetBSD: patch-include_libfyaml_libfyaml-util.h,v 1.1 2026/04/01 08:53:14 tnn Exp $

https://github.com/pantoniou/libfyaml/commit/e7f1b117d458e202498f0a3862761661c26ca7ae.patch

--- include/libfyaml/libfyaml-util.h.orig	2026-03-15 13:48:50.000000000 +0000
+++ include/libfyaml/libfyaml-util.h
@@ -797,7 +797,11 @@ static inline char *fy_alloca_vsprintf_i
 #define _E8(...)	_E4(_E4(__VA_ARGS__))
 #define _E16(...)	_E8(_E8(__VA_ARGS__))
 #define _E32(...)	_E16(_E16(__VA_ARGS__))
+#if !defined(__SIZEOF_POINTER__) || __SIZEOF_POINTER__ >= 8
 #define _E(...)		_E32(_E32(__VA_ARGS__))
+#else
+#define _E(...)		_E16(_E16(__VA_ARGS__))
+#endif
 
 #define _FMT()
 #define _FP1(m) m _FMT()
@@ -1054,12 +1058,12 @@ static inline char *fy_alloca_vsprintf_i
 #define FY_CPP_EVAL2(...)	FY_CPP_EVAL1(FY_CPP_EVAL1(__VA_ARGS__))
 #define FY_CPP_EVAL4(...)	FY_CPP_EVAL2(FY_CPP_EVAL2(__VA_ARGS__))
 #define FY_CPP_EVAL8(...)	FY_CPP_EVAL4(FY_CPP_EVAL4(__VA_ARGS__))
-#if !defined(__clang__)
-// gcc is better, goes to 16
+#if !defined(__clang__) && (!defined(__SIZEOF_POINTER__) || __SIZEOF_POINTER__ >= 8)
+// 64-bit gcc can afford the deeper expansion tree.
 #define FY_CPP_EVAL16(...)	FY_CPP_EVAL8(FY_CPP_EVAL8(__VA_ARGS__))
 #define FY_CPP_EVAL(...)	FY_CPP_EVAL16(FY_CPP_EVAL16(__VA_ARGS__))
 #else
-// clang craps out at 8
+// clang and 32-bit builds use a shallower expansion tree to keep cc1 memory use in check.
 #define FY_CPP_EVAL(...)	FY_CPP_EVAL8(FY_CPP_EVAL8(__VA_ARGS__))
 #endif
 
