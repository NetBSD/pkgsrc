$NetBSD: patch-mono_metadata_icall.c,v 1.2 2019/10/09 22:46:04 maya Exp $

NetBSD will side-load <stdbool.h> which must have #define bool _Bool.
This causes some problems with the C preprocessor usage here. undef it.

--- mono/metadata/icall.c.orig	2019-09-19 07:46:07.000000000 +0000
+++ mono/metadata/icall.c
@@ -120,6 +120,8 @@
 #include "mono/utils/mono-threads-coop.h"
 #include "mono/metadata/icall-signatures.h"
 
+#undef bool
+
 //#define MONO_DEBUG_ICALLARRAY
 
 #ifdef MONO_DEBUG_ICALLARRAY
