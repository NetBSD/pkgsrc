$NetBSD: patch-src_mulDo.c,v 1.1 2012/10/20 22:03:46 joerg Exp $

--- src/mulDo.c.orig	2012-10-20 10:20:10.000000000 +0000
+++ src/mulDo.c
@@ -150,8 +150,7 @@ int type;
 /* 
 Loop through upward pass. 
 */
-mulUp(sys)
-ssystem *sys;
+void mulUp(ssystem *sys)
 {
 int i, j, k, l;
 int msize;
@@ -224,8 +223,7 @@ ssystem *sys;
 /* 
 Loop through downward pass. 
 */
-mulDown(sys)
-ssystem *sys;
+void mulDown(ssystem *sys)
 {
   cube *nc;
   int depth, i, j, k, lsize;
