$NetBSD: patch-test_mocklibc_src_grp.c,v 1.2 2016/06/18 12:16:23 youri Exp $

* XXX: no fgetgrent(3)

--- test/mocklibc/src/grp.c.orig	2014-01-14 22:42:25.000000000 +0000
+++ test/mocklibc/src/grp.c
@@ -27,6 +27,12 @@
 
 static FILE *global_stream = NULL;
 
+#if defined(__NetBSD__) || defined(__FreeBSD__)
+static struct group *fgetgrent(FILE *stream) {
+  return NULL;
+}
+#endif
+
 void setgrent(void) {
   if (global_stream)
     endgrent();
