$NetBSD: patch-main.c,v 1.1 2015/02/23 18:24:00 joerg Exp $

--- main.c.orig	2015-02-23 13:30:37.000000000 +0000
+++ main.c
@@ -150,7 +150,7 @@ int main(int argc, char **argv)
                 strncpy(command, p, 1024);
                 free(p);
 #else
-                printf(prompt);
+                printf("%s", prompt);
                 if (fgets(command, 1024, stdin) == NULL)
                         continue;
                 command[1023] = '\0';
