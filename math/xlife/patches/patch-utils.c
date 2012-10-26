$NetBSD: patch-utils.c,v 1.1 2012/10/26 20:39:57 joerg Exp $

--- utils.c.orig	2012-10-26 14:13:06.000000000 +0000
+++ utils.c
@@ -20,6 +20,7 @@
  * PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <stdlib.h>
 #include "defs.h"
 #include "tile.h"
 #include <pwd.h>
