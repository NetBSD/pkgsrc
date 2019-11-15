$NetBSD: patch-src_libpst.c,v 1.1 2019/11/15 11:09:15 sborrill Exp $

Fix segfault as per:
https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=875894#25

Fix will be in next release

--- src/libpst.c.orig	2019-11-14 16:48:41.000000000 +0000
+++ src/libpst.c	2019-11-14 16:49:24.000000000 +0000
@@ -409,6 +409,10 @@
 
 int pst_close(pst_file *pf) {
     DEBUG_ENT("pst_close");
+    if (!pf) {
+        DEBUG_RET();
+        return 0;
+    }
     if (!pf->fp) {
         DEBUG_RET();
         return 0;
