$NetBSD: patch-test_mocklibc_src_pwd.c,v 1.2 2016/06/18 12:16:23 youri Exp $

* XXX: no fgetpwent(3)

--- test/mocklibc/src/pwd.c.orig	2014-01-14 22:42:25.000000000 +0000
+++ test/mocklibc/src/pwd.c
@@ -27,6 +27,12 @@
 
 static FILE *global_stream = NULL;
 
+#if defined(__NetBSD__) || defined(__FreeBSD__)
+static struct passwd *fgetpwent(FILE* stream) {
+  return NULL;
+}
+#endif
+
 void setpwent(void) {
   if (global_stream)
     endpwent();
