$NetBSD: patch-app_gradient.c,v 1.1 2012/07/03 18:08:21 joerg Exp $

--- app/gradient.c.orig	2012-07-03 13:54:31.000000000 +0000
+++ app/gradient.c
@@ -5451,7 +5451,7 @@ grad_load_gradient(char *filename)
           g_message (_("Corrupt segment %d in gradient file '%s'."),
                      i, filename);
           fclose (file);
-          return NULL;
+          return;
         }
 #else
 		if (sscanf(line, "%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%d%d",
