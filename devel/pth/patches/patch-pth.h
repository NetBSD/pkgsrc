$NetBSD: patch-pth.h,v 1.1 2026/01/03 09:58:50 wiz Exp $

Provide prototype for pth__init().

--- pth.h.orig	2026-01-03 09:57:34.450040462 +0000
+++ pth.h
@@ -419,6 +419,7 @@ typedef void *Sfdisc_t;
 
     /* global functions */
 extern int            pth_init(void);
+extern int            pth__init(void);
 extern int            pth_kill(void);
 extern long           pth_ctrl(unsigned long, ...);
 extern long           pth_version(void);
