$NetBSD: patch-src_seq_seq__midi__event.c,v 1.4 2024/02/21 08:58:01 wiz Exp $

--- src/seq/seq_midi_event.c.orig	2024-01-29 16:16:07.000000000 +0000
+++ src/seq/seq_midi_event.c
@@ -31,6 +31,8 @@
 #include "local.h"
 #if HAVE_MALLOC_H
 #include <malloc.h>
+#else
+#include <stdlib.h>
 #endif
 
 #ifndef DOC_HIDDEN
