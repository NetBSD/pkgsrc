$NetBSD: patch-test_mocklibc_src_grp.c,v 1.4 2016/12/03 01:58:50 marino Exp $

* XXX: no fgetgrent(3)

Avoid conflicting with builtin setgrent on FreeBSD, it has a different
prototype: int setgrent(void)

--- test/mocklibc/src/grp.c.orig	2014-01-14 22:42:25.000000000 +0000
+++ test/mocklibc/src/grp.c
@@ -27,6 +27,13 @@
 
 static FILE *global_stream = NULL;
 
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+static struct group *fgetgrent(FILE *stream) {
+  return NULL;
+}
+#endif
+
+#if !defined(__FreeBSD__)
 void setgrent(void) {
   if (global_stream)
     endgrent();
@@ -37,6 +44,7 @@ void setgrent(void) {
 
   global_stream = fopen(path, "r");
 }
+#endif
 
 struct group *getgrent(void) {
   if (!global_stream)
