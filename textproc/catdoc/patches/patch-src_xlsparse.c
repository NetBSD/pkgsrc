$NetBSD: patch-src_xlsparse.c,v 1.1 2013/12/16 19:35:16 asau Exp $

--- src/xlsparse.c.orig	2012-12-03 18:03:52.000000000 +0000
+++ src/xlsparse.c	2013-12-16 19:31:35.196505723 +0000
@@ -8,6 +8,7 @@
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
+#include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
 #include "xls.h"
