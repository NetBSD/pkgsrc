$NetBSD: patch-newsnd.c,v 1.1 2013/10/10 00:07:23 joerg Exp $

--- newsnd.c.orig	2013-10-09 23:17:26.000000000 +0000
+++ newsnd.c
@@ -207,7 +207,7 @@ samp getsample(void)
 
   if (i8flag && i8pulse<=0) {
     f=TRUE;
-    if (spkrmode!=0)
+    if (spkrmode!=0) {
       if (spkrmode!=1)
         t2sw=!t2sw;
       else {
@@ -215,6 +215,7 @@ samp getsample(void)
         t2sw=TRUE;
         f=FALSE;
       }
+    }
   }
 
   if (i8pulse>0) {
