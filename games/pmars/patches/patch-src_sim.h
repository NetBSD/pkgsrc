$NetBSD: patch-src_sim.h,v 1.1 2016/06/11 18:41:56 kamil Exp $

Fix name clash with builtin 'round'.

--- src/sim.h.orig	2000-08-20 13:29:44.000000000 +0000
+++ src/sim.h
@@ -89,7 +89,7 @@ extern int displayMode;
 #define FAR
 #endif
 
-extern int round;
+extern int sim_round;
 extern long cycle;
 extern ADDR_T progCnt;                /* program counter */
 extern warrior_struct *W;        /* indicate which warrior is running */
