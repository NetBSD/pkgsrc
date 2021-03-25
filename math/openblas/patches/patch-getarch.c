$NetBSD: patch-getarch.c,v 1.2 2021/03/25 23:22:35 thor Exp $

Do not override our parallel make choice.

--- getarch.c.orig	2020-11-11 22:35:05.756907595 +0000
+++ getarch.c
@@ -1369,19 +1369,6 @@ printf("__BYTE_ORDER__=__ORDER_BIG_ENDIA
 printf("ELF_VERSION=2\n");
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
