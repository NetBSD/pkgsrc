$NetBSD: patch-mono_metadata_icall.c,v 1.1 2019/08/25 16:37:01 maya Exp $

NetBSD will side-load <stdbool.h> which must have #define bool _Bool.
This causes some problems with the C preprocessor usage here. undef it.

--- mono/metadata/icall.c.orig	2019-07-18 07:46:08.000000000 +0000
+++ mono/metadata/icall.c
@@ -117,6 +117,8 @@
 #include "icall-decl.h"
 #include "mono/utils/mono-threads-coop.h"
 
+#undef bool
+
 //#define MONO_DEBUG_ICALLARRAY
 
 #ifdef MONO_DEBUG_ICALLARRAY
