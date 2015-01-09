$NetBSD: patch-tools_mkmake_mkmake.y,v 1.1 2015/01/09 14:28:42 joerg Exp $

--- tools/mkmake/mkmake.y.orig	2015-01-09 12:31:43.000000000 +0000
+++ tools/mkmake/mkmake.y
@@ -40,6 +40,7 @@ __RCSID("$NetBSD: mkmake.y,v 1.1.1.1 201
 #endif
 #endif /* not lint */
 #endif
+#include <stdlib.h>
 
 typedef struct string {
     int
