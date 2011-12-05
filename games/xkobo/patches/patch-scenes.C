$NetBSD: patch-scenes.C,v 1.1 2011/12/05 22:48:03 joerg Exp $

--- scenes.C.orig	2011-12-05 19:54:57.000000000 +0000
+++ scenes.C
@@ -22,7 +22,7 @@
 
 #include "scenes.h"
 
-_scene scene[] = {
+extern "C" _scene scene[] = {
     /* 1 */
     {
         0, 32, 96,
