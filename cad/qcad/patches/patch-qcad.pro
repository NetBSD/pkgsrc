$NetBSD: patch-qcad.pro,v 1.4 2019/07/31 19:30:21 plunky Exp $

disable searching outside of the source directory

--- qcad.pro.orig	2017-07-21 17:57:53.000000000 +0000
+++ qcad.pro
@@ -12,7 +12,7 @@ win32 {
     }
 }
 else {
-    SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$")
+    #SUBDIRS += $$system("ls -d ../qcad?* 2>/dev/null | grep -v $(basename $(pwd))$")
 }
 
 !r_mobile {
