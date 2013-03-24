$NetBSD: patch-vncpasswd_vncpasswd.c,v 1.1 2013/03/24 16:49:44 joerg Exp $

--- vncpasswd/vncpasswd.c.orig	2013-03-23 18:21:41.000000000 +0000
+++ vncpasswd/vncpasswd.c
@@ -84,7 +84,7 @@ int main(int argc, char *argv[]) {
       }
       for (i = 0; i < strlen(passwd); i++)
 	passwd[i] = passwd1[i] = '\0';
-      return;
+      return 0;
     }
 
     fprintf(stderr,"They don't match. Try again.\n\n");
