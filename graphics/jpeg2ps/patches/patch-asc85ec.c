$NetBSD: patch-asc85ec.c,v 1.1 2026/03/18 10:07:34 nia Exp $

Have to include <stdlib.h> unconditionally since this uses exit(3).

--- asc85ec.c.orig	2026-03-18 09:42:55.891192635 +0000
+++ asc85ec.c
@@ -2,6 +2,7 @@
 /* (C) Thomas Merz 1994-2002 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <fcntl.h>
 
 /* try to identify Mac compilers */
@@ -15,7 +16,6 @@
 
 #ifdef DOS
 #include <io.h>
-#include <stdlib.h>
 #endif
 
 #include "psimage.h"
