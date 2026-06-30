$NetBSD: patch-canuum_canna.c,v 1.2 2026/06/30 14:17:52 tsutsui Exp $

- Remove unnecessary ops.
- Remove non-standard and unnecessary resetterm()

--- canuum/canna.c.orig	2026-05-09 14:08:44.000000000 +0000
+++ canuum/canna.c
@@ -1248,10 +1248,8 @@ int flag;
 #endif
 
 #ifdef TERMINFO
-  int fd, res;
 
-  fd = open("/dev/null", O_WRONLY, &res);
-  setupterm(term, fd, (int *)0);
+  setupterm(term, STDOUT_FILENO, NULL);
 
   cannakeyentry(key_f1,    CANNA_KEY_F1);
   cannakeyentry(key_f2,    CANNA_KEY_F2);
@@ -1280,7 +1278,6 @@ int flag;
   cannakeyentry(key_end,   CANNA_KEY_End);
 #endif
 
-  resetterm();
 #endif
 
   if (terminalname = malloc(strlen(term) + 1)) {
