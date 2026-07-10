$NetBSD: patch-Wnn_jserver_kaiseki.h,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Use proper function prototypes

--- Wnn/jserver/kaiseki.h.orig	2003-05-11 18:35:54.000000000 +0000
+++ Wnn/jserver/kaiseki.h
@@ -62,8 +62,8 @@
 
 #define _DIVID(val, div)        (((int)(val) > (int)0) ? ((val) / (div)) : ((val) * (div)))
 
-extern struct fzkkouho *getfzkoh_body ();
-extern struct fzkkouho *getfzkoh1_body ();
+extern struct fzkkouho *getfzkoh_body (struct ICHBNP *, int);
+extern struct fzkkouho *getfzkoh1_body (struct ICHBNP *, int);
 
 #define getfzkoh(ichbnp_p,no) \
         (((int)(no) < (int)FZKIBNO) ? &((ichbnp_p)->fzkib[no]) : getfzkoh_body(ichbnp_p,no))
