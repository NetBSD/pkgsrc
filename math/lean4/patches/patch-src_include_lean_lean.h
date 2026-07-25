$NetBSD: patch-src_include_lean_lean.h,v 1.2 2026/07/25 11:24:52 wiz Exp $

Call compiler-provided alloca(). Fixes
Warning: reference to the libc supplied alloca(3); this most likely will not work. Please use the compiler provided version of alloca(3), by supplying the appropriate compiler flags (e.g. -std=gnu99).
https://github.com/leanprover/lean4/pull/14543

--- src/include/lean/lean.h.orig	2026-07-25 09:24:11.724804692 +0000
+++ src/include/lean/lean.h
@@ -37,7 +37,11 @@ extern "C" {
 #include <stdnoreturn.h>
 #define LEAN_NORETURN _Noreturn
 #else
+#if defined(__GNUC__) || defined(__clang__)
+#define LEAN_ALLOCA(s) __builtin_alloca(s)
+#else
 #define LEAN_ALLOCA(s) alloca(s)
+#endif
 #define LEAN_NORETURN __attribute__((noreturn))
 #endif
 
