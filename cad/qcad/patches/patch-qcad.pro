$NetBSD: patch-qcad.pro,v 1.2 2017/03/18 19:39:17 plunky Exp $

disable searching outside of the source directory

--- qcad.pro.orig	2017-03-17 14:09:31.000000000 +0000
+++ qcad.pro
@@ -13,7 +13,7 @@ win32 {
     }
 }
 else {
-    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v qcadmobile")
+    #SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v qcadmobile")
 }
 
 !r_mobile {
