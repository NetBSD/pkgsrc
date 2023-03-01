$NetBSD: patch-legend.c,v 1.1 2023/03/01 23:48:00 vins Exp $

Pull patches from Debian.

--- legend.c.orig	1994-05-19 02:01:08.000000000 +0000
+++ legend.c
@@ -1,5 +1,5 @@
-#ifndef lint
-static char rcsid[] = "legend.c,v 2.0 1994/05/19 02:01:08 dan Exp";
+#if 0
+static char rcsid[] __attribute__((unused)) = "legend.c,v 2.0 1994/05/19 02:01:08 dan Exp";
 #endif
 
 /*
