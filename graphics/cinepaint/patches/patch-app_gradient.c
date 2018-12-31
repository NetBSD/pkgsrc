$NetBSD: patch-app_gradient.c,v 1.2 2018/12/31 13:11:12 ryoon Exp $

--- app/gradient.c.orig	2007-11-09 15:24:27.000000000 +0000
+++ app/gradient.c
@@ -5452,7 +5452,7 @@ grad_load_gradient(char *filename)
           g_message (_("Corrupt segment %d in gradient file '%s'."),
                      i, filename);
           fclose (file);
-          return NULL;
+          return;
         }
 #else
 		if (sscanf(line, "%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%d%d",
