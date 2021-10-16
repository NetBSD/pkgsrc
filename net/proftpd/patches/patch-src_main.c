$NetBSD: patch-src_main.c,v 1.2 2021/10/16 19:46:42 tm Exp $

Add packet filter

--- src/main.c.orig	Tue Jul 21 17:25:51 2020
+++ src/main.c	Fri Oct 15 09:29:42 2021
@@ -41,6 +41,7 @@
 #endif
 
 #include "privs.h"
+#include "pfilter.h"
 
 #ifdef PR_USE_OPENSSL
 # include <openssl/opensslv.h>
@@ -1116,6 +1117,7 @@
   pid_t pid;
   sigset_t sig_set;
 
+  pfilter_init();
   if (no_fork == FALSE) {
 
     /* A race condition exists on heavily loaded servers where the parent
@@ -1233,7 +1235,8 @@
 
   /* Reseed pseudo-randoms */
   pr_random_init();
-
+#else
+  pfilter_init(); 
 #endif /* PR_DEVEL_NO_FORK */
 
   /* Child is running here */
