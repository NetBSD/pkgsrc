$NetBSD: patch-rxstack.c,v 1.1 2026/08/01 18:11:29 ryoon Exp $

--- rxstack.c.orig	1996-08-01 15:41:44.000000000 +0000
+++ rxstack.c
@@ -4,6 +4,7 @@
 #include<stdlib.h>
 #include<string.h>
 #include<signal.h>
+#include<unistd.h>
 #include<sys/types.h>
 #include<sys/socket.h>
 
@@ -15,8 +16,10 @@ int s;                               /* The socket fd 
 char *buff;                          /* An input buffer */
 unsigned bufflen;                    /* The amount of memory allocated */
 int s;                               /* The socket fd */
+int x2d(char *);
+int pop(char, int);
 
-main(argc,argv)
+int main(argc,argv)
 int argc;
 char **argv;
 {
