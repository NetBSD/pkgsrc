$NetBSD: patch-src_main.c,v 1.1 2019/10/07 19:29:47 christos Exp $

Add packet filter

--- src/main.c.orig	2017-04-09 22:31:02.000000000 -0400
+++ src/main.c	2019-10-07 15:09:12.516004304 -0400
@@ -41,6 +41,7 @@
 #endif
 
 #include "privs.h"
+#include "pfilter.h"
 
 int (*cmd_auth_chk)(cmd_rec *);
 void (*cmd_handler)(server_rec *, conn_t *);
@@ -1089,6 +1090,7 @@
   pid_t pid;
   sigset_t sig_set;
 
+  pfilter_init();
   if (no_fork == FALSE) {
 
     /* A race condition exists on heavily loaded servers where the parent
@@ -1206,7 +1208,8 @@
 
   /* Reseed pseudo-randoms */
   srand((unsigned int) (time(NULL) * getpid()));
-
+#else
+  pfilter_init();
 #endif /* PR_DEVEL_NO_FORK */
 
   /* Child is running here */
