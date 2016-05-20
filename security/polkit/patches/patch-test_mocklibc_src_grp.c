$NetBSD: patch-test_mocklibc_src_grp.c,v 1.1 2016/05/20 18:39:33 youri Exp $

* XXX: no fgetgrent(3)

--- test/mocklibc/src/grp.c.orig	2014-01-14 22:42:25.000000000 +0000
+++ test/mocklibc/src/grp.c
@@ -27,6 +27,12 @@
 
 static FILE *global_stream = NULL;
 
+#ifdef __NetBSD__
+static struct group *fgetgrent(FILE *stream) {
+  return NULL;
+}
+#endif
+
 void setgrent(void) {
   if (global_stream)
     endgrent();
