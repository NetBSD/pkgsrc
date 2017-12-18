$NetBSD: patch-qcad.pro,v 1.3 2017/12/18 21:21:44 plunky Exp $

disable searching outside of the source directory

--- qcad.pro.orig	2017-07-21 17:57:53.000000000 +0000
+++ qcad.pro
@@ -13,7 +13,7 @@ win32 {
     }
 }
 else {
-    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$ | grep -v qcadmobile")
+    #SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$ | grep -v qcadmobile")
 }
 
 !r_mobile {
