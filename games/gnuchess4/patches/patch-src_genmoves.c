$NetBSD: patch-src_genmoves.c,v 1.1 2012/12/20 22:02:13 joerg Exp $

--- src/genmoves.c.orig	2012-12-20 19:22:41.000000000 +0000
+++ src/genmoves.c
@@ -36,7 +36,7 @@ SHORT *TrP, InCheck;
 	     (*TrP)++;\
 	     }
 
-inline int
+static inline int
 CheckMove (SHORT f, SHORT t, SHORT flag)
 {
   SHORT side, incheck;
@@ -55,7 +55,7 @@ CheckMove (SHORT f, SHORT t, SHORT flag)
 
 
 
-inline void
+static inline void
 LinkMove (SHORT ply, SHORT f,
 	  register SHORT t,
 	  SHORT flag,
@@ -129,7 +129,7 @@ LinkMove (SHORT ply, SHORT f,
     Link (f, t, flag, s - 20000);
 }
 
-inline
+static inline
 void
 GenMoves (register SHORT ply, register SHORT sq, SHORT side, SHORT xside)
 
@@ -374,7 +374,7 @@ CaptureList (register SHORT side, SHORT 
     GenCnt += (TrPnt[ply + 1] - TrPnt[ply]);
 }
 
-inline
+static inline
 void
 VGenMoves (register SHORT ply, register SHORT sq, SHORT side, SHORT xside)
 
