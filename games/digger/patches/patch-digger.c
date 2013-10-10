$NetBSD: patch-digger.c,v 1.1 2013/10/10 00:07:23 joerg Exp $

--- digger.c.orig	2013-10-09 23:14:54.000000000 +0000
+++ digger.c
@@ -153,7 +153,7 @@ void dodigger(void)
       drawexplosion(n);
     else
       updatefire(n);
-    if (digvisible)
+    if (digvisible) {
       if (digdat[n].alive)
         if (digdat[n].bagtime!=0) {
           drawdig(n,digdat[n].mdir,digdat[n].x,digdat[n].y,
@@ -165,6 +165,7 @@ void dodigger(void)
           updatedigger(n);
       else
         diggerdie(n);
+    }
     if (digdat[n].emocttime>0)
       digdat[n].emocttime--;
   }
