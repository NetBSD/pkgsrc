$NetBSD: patch-src_tkgate_edit.c,v 1.1 2013/03/02 18:29:03 joerg Exp $

--- src/tkgate/edit.c.orig	2013-03-01 14:52:29.000000000 +0000
+++ src/tkgate/edit.c
@@ -747,7 +747,7 @@ char *PrintNet(char *p,GNet *net)
 
   if (!net) {
     p += sprintf(p,"NetID:    *null*\n");
-    return;
+    return NULL;
   }
 
   name = net->signame ? net->signame : "*none*";
