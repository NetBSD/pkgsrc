$NetBSD: patch-lifeconv.c,v 1.1 2012/10/26 20:39:57 joerg Exp $

--- lifeconv.c.orig	2012-10-26 14:12:40.000000000 +0000
+++ lifeconv.c
@@ -25,6 +25,8 @@
  */
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
+#include <unistd.h>
 
 typedef int	bool;
 #define TRUE	1
@@ -116,7 +118,7 @@ FILE	*ofp;
 	    linenum++;
 	}
 
-	return;
+	return mode;
     }
 
 
