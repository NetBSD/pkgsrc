$NetBSD: patch-main.h,v 1.1 2021/08/27 03:41:41 ryoon Exp $

* Forward declare init() in main.c to use from xcopilot.c.

--- main.h.orig	1998-08-22 20:25:01.000000000 +0000
+++ main.h
@@ -33,3 +33,5 @@ typedef struct {
   /* thread variables */
   int threads;        /* number of threads created */
 } Pilot, *Pilot_P;
+
+int init(Pilot *);
