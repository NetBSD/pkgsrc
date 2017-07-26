$NetBSD: patch-ezmlm-manage.c,v 1.2 2017/07/26 02:02:23 schmonz Exp $

Add some prototypes, missing headers and redefine log() to not conflict
with libm.

--- ezmlm-manage.c.orig	2013-02-25 16:48:08.000000000 +0000
+++ ezmlm-manage.c
@@ -22,6 +22,7 @@
 #include "fmt.h"
 #include "subscribe.h"
 #include "cookie.h"
+#include "log.h"
 
 #define FATAL "ezmlm-manage: fatal: "
 void die_usage() { strerr_die1x(100,"ezmlm-manage: usage: ezmlm-manage dir"); }
@@ -129,9 +130,7 @@ char *fn;
 
 stralloc mydtline = {0};
 
-void main(argc,argv)
-int argc;
-char **argv;
+int main(int argc, char **argv)
 {
   char *dir;
   char *sender;
