$NetBSD: patch-mono_metadata_icall.c,v 1.2 2021/03/03 12:05:41 nia Exp $

NetBSD will side-load <stdbool.h> which must have #define bool _Bool.
This causes some problems with the C preprocessor usage here. undef it.

--- mono/metadata/icall.c.orig	2020-04-30 07:46:10.000000000 +0000
+++ mono/metadata/icall.c
@@ -120,6 +120,8 @@
 #include "mono/metadata/icall-signatures.h"
 #include "mono/utils/mono-signal-handler.h"
 
+#undef bool
+
 //#define MONO_DEBUG_ICALLARRAY
 
 #ifdef MONO_DEBUG_ICALLARRAY
