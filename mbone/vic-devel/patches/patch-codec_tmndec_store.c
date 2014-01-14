$NetBSD: patch-codec_tmndec_store.c,v 1.1 2014/01/14 17:07:37 prlw1 Exp $

--- codec/tmndec/store.c.orig	2008-12-10 19:23:32.000000000 +0000
+++ codec/tmndec/store.c
@@ -64,6 +64,8 @@
 #include <fcntl.h>
 #ifdef WIN32
 #include <io.h>
+#else
+#include <unistd.h>
 #endif
 
 #include "config.h"
