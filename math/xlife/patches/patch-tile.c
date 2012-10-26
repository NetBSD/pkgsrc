$NetBSD: patch-tile.c,v 1.1 2012/10/26 20:39:57 joerg Exp $

--- tile.c.orig	2012-10-26 14:13:23.000000000 +0000
+++ tile.c
@@ -61,6 +61,7 @@
  */
 
 #include <stddef.h>	/* we need offsetof() */
+#include <stdlib.h>
 #include "defs.h"
 #include "data.h"
 #include "tile.h"
