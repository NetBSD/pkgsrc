$NetBSD: patch-src_libopts_libopts.c,v 1.1 2015/06/08 13:44:57 joerg Exp $

Workaround broken gettext.h conflicting with native implementation of
message contexts in NetBSD.

--- src/libopts/libopts.c.orig	2015-06-08 13:12:30.000000000 +0000
+++ src/libopts/libopts.c
@@ -1,3 +1,7 @@
+#include <config.h>
+#if ENABLE_NLS
+#include <gettext.h>
+#endif
 #define  AUTOOPTS_INTERNAL 1
 #include "autoopts/project.h"
 #define  LOCAL static
