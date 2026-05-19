$NetBSD: patch-lib_internal.h,v 1.9 2026/05/19 08:41:36 jperkin Exp $

Fix symbol versioning on illumos.

--- lib/internal.h.orig	2026-04-05 18:16:44.000000000 +0000
+++ lib/internal.h
@@ -19,7 +19,7 @@
 // mechanism, have to be declared as VERSIONED. Otherwise, GCC with global
 // optimizations is happy to optimize them away, leading to linker failures.
 #define VERSIONED_ABI __attribute__((used)) PCI_ABI
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__illumos__)
 #define STATIC_ALIAS(_decl, _for) VERSIONED_ABI _decl { return _for; }
 #define DEFINE_ALIAS(_decl, _for)
 #define SYMBOL_VERSION(_int, _ext)
