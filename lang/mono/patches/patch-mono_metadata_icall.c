$NetBSD: patch-mono_metadata_icall.c,v 1.3 2026/02/03 15:17:53 ryoon Exp $

NetBSD will side-load <stdbool.h> which must have #define bool _Bool.
This causes some problems with the C preprocessor usage here. undef it.

--- mono/metadata/icall.c.orig	2025-04-29 17:18:29.000000000 +0000
+++ mono/metadata/icall.c
@@ -127,6 +127,8 @@
 #undef bool
 #endif
 
+#undef bool
+
 //#define MONO_DEBUG_ICALLARRAY
 
 // Inline with CoreCLR heuristics, https://github.com/dotnet/runtime/blob/69e114c1abf91241a0eeecf1ecceab4711b8aa62/src/coreclr/vm/threads.cpp#L6408.
