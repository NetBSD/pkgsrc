$NetBSD: patch-src_libopts_libopts.c,v 1.2 2019/12/06 14:00:08 nia Exp $

Workaround broken gettext.h conflicting with native implementation of
message contexts in NetBSD.

--- src/libopts/libopts.c.orig	2019-12-01 21:25:38.000000000 +0000
+++ src/libopts/libopts.c
@@ -1,3 +1,7 @@
+#include <config.h>
+#if ENABLE_NLS
+#include <gettext.h>
+#endif
 #define  AUTOOPTS_INTERNAL 1
 #include "autoopts/project.h"
 
