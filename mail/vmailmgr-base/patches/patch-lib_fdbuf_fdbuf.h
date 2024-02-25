$NetBSD: patch-lib_fdbuf_fdbuf.h,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Fix warnings.

--- lib/fdbuf/fdbuf.h.orig	2024-02-20 03:19:48.448432259 +0000
+++ lib/fdbuf/fdbuf.h
@@ -21,6 +21,7 @@
 #include "config.h"
 #include <string.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #ifdef _REENTRANT
 #include <pthread.h>
