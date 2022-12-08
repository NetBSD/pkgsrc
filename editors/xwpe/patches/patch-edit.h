$NetBSD: patch-edit.h,v 1.2 2022/12/08 10:31:08 vins Exp $

Fix typo in int declaration.

--- edit.h.orig	2005-07-07 01:53:09.000000000 +0000
+++ edit.h
@@ -793,7 +793,7 @@ int e_d_reinit_watches(FENSTER *f,char *
 
 /* we_gpm.c */
 #ifdef HAVE_LIBGPM
-int WpeGpmInit(void);
+int WpeGpmMouseInit(void);
 int WpeGpmMouse(int *g);
 #endif
 
