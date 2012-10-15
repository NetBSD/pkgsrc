$NetBSD: patch-tagutils.c,v 1.1 2012/10/15 22:48:02 drochner Exp $

--- tagutils/tagutils.c.orig	2012-10-15 19:50:35.000000000 +0000
+++ tagutils/tagutils.c
@@ -40,6 +40,7 @@
 #ifdef HAVE_ICONV_H
 #include <iconv.h>
 #endif
+#include <libgen.h>
 
 #include <sqlite3.h>
 #include "tagutils.h"
