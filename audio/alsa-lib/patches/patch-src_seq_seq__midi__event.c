$NetBSD: patch-src_seq_seq__midi__event.c,v 1.3 2023/11/23 16:15:04 ryoon Exp $

--- src/seq/seq_midi_event.c.orig	2023-05-04 07:16:16.000000000 +0000
+++ src/seq/seq_midi_event.c
@@ -30,6 +30,8 @@
 
 #if HAVE_MALLOC_H
 #include <malloc.h>
+#else
+#include <stdlib.h>
 #endif
 #include "local.h"
 
