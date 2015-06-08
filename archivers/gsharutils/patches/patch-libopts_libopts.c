$NetBSD: patch-libopts_libopts.c,v 1.1 2015/06/08 23:13:52 joerg Exp $

--- libopts/libopts.c.orig	2015-06-08 20:10:35.000000000 +0000
+++ libopts/libopts.c
@@ -1,3 +1,9 @@
+#include "config.h"
+#if ENABLE_NLS
+#ifdef HAVE_DCGETTEXT
+# include <gettext.h>
+#endif
+#endif
 #define  AUTOOPTS_INTERNAL 1
 #include "autoopts/project.h"
 #define  LOCAL static
