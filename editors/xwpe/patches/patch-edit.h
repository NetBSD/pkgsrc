$NetBSD: patch-edit.h,v 1.1 2022/12/08 08:51:56 vins Exp $

Fix typo in int declaration.

--- edit.h.orig	2005-07-07 01:53:09.000000000 +0000
+++ edit.h
@@ -794,7 +794,7 @@ int e_d_reinit_watches(FENSTER *f,char *
 /* we_gpm.c */
 #ifdef HAVE_LIBGPM
 int WpeGpmInit(void);
-int WpeGpmMouse(int *g);
+int WpeGpmMouseInit(void);
 #endif
 
 /* WeLinux.c */
