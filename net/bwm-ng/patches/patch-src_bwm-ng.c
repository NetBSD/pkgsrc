$NetBSD: patch-src_bwm-ng.c,v 1.1 2019/02/12 14:43:17 wiz Exp $

Make sure init() exists, even though inline.

--- src/bwm-ng.c.orig	2015-07-23 05:17:29.000000000 +0000
+++ src/bwm-ng.c
@@ -26,7 +26,7 @@
 
 /* handle interrupt signal */
 void sigint(int sig) FUNCATTR_NORETURN;
-inline void init(void);
+static inline void init(void);
 
 /* clear stuff and exit */
 #ifdef __STDC__
