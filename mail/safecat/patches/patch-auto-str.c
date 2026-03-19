$NetBSD: patch-auto-str.c,v 1.1 2026/03/19 07:50:46 nia Exp $

Fix conflict with libc function.

--- auto-str.c.orig	2000-02-29 04:10:12.000000000 +0000
+++ auto-str.c
@@ -5,11 +5,12 @@
 char buf1[256];
 substdio ss1 = SUBSTDIO_FDBUF(write,1,buf1,sizeof(buf1));
 
-void puts(s)
+void myputs(s)
 char *s;
 {
   if (substdio_puts(&ss1,s) == -1) _exit(111);
 }
+#define puts myputs
 
 void main(argc,argv)
 int argc;
