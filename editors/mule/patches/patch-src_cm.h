$NetBSD: patch-src_cm.h,v 1.1 2013/04/21 15:39:59 joerg Exp $

--- src/cm.h.orig	1993-09-12 01:20:36.000000000 +0000
+++ src/cm.h
@@ -164,6 +164,6 @@ extern int evalcost ();
 
 extern void cmputc ();
 extern int cmcostinit ();
-extern int cmgoto ();
+extern void cmgoto (int, int);
 extern int Wcm_clear ();
 extern int Wcm_init ();
