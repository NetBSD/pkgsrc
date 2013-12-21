$NetBSD: patch-config_auto__aux_gethostbyname.c,v 1.1 2013/12/21 16:21:20 christos Exp $

--- config/auto-aux/gethostbyname.c.orig	2012-10-15 13:50:56.000000000 -0400
+++ config/auto-aux/gethostbyname.c	2013-12-21 11:16:39.000000000 -0500
@@ -19,6 +19,10 @@
 #include <sys/types.h>
 #include <netdb.h>
 
+#ifdef __NetBSD__
+#error "the test does not handle missing prototypes"
+#endif
+
 int main(int argc, char ** argv)
 {
 #if NUM_ARGS == 5
