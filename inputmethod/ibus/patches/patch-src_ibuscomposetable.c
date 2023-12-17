$NetBSD: patch-src_ibuscomposetable.c,v 1.1 2023/12/17 09:04:10 nros Exp $

include strings.h for index(3)

--- src/ibuscomposetable.c.orig	2023-12-17 09:46:36.902795436 +0000
+++ src/ibuscomposetable.c
@@ -26,6 +26,7 @@
 #include <glib/gstdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 
 #include "ibuscomposetable.h"
 #include "ibuserror.h"
