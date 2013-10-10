$NetBSD: patch-monster.c,v 1.1 2013/10/10 00:07:23 joerg Exp $

--- monster.c.orig	2013-10-09 23:17:45.000000000 +0000
+++ monster.c
@@ -394,7 +394,7 @@ void monai(Sint4 mon)
 
   /* Collision with Digger */
 
-  if (clfirst[4]!=-1 && isalive())
+  if (clfirst[4]!=-1 && isalive()) {
     if (bonusmode) {
       killmon(mon);
       i=clfirst[4];
@@ -413,6 +413,7 @@ void monai(Sint4 mon)
         i=clcoll[i];
       }
     }
+  }
 
   /* Update co-ordinates */
 
