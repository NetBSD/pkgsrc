$NetBSD: patch-getarch.c,v 1.1 2020/11/05 16:31:45 bacon Exp $

Do not override our parallel make choice.

--- getarch.c.orig	2018-12-31 23:09:59.000000000 +0100
+++ getarch.c	2019-03-22 17:24:40.477260427 +0100
@@ -1236,19 +1236,6 @@
 #endif
 #endif
 
-#ifdef MAKE_NB_JOBS
-  #if MAKE_NB_JOBS > 0
-    printf("MAKE += -j %d\n", MAKE_NB_JOBS);
-  #else
-    // Let make use parent -j argument or -j1 if there
-    // is no make parent
-  #endif
-#elif NO_PARALLEL_MAKE==1
-    printf("MAKE += -j 1\n");
-#else
-    printf("MAKE += -j %d\n", get_num_cores());
-#endif
-
     break;
 
   case '1' : /* For config.h */
