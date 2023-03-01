$NetBSD: patch-modal.c,v 1.1 2023/03/01 23:48:00 vins Exp $

Pull patches from Debian.

--- modal.c.orig	1994-05-19 02:01:20.000000000 +0000
+++ modal.c
@@ -1,5 +1,5 @@
-#ifndef lint
-static char rcsid[] = "modal.c,v 2.0 1994/05/19 02:01:20 dan Exp";
+#if 0
+static char rcsid[] __attribute__((unused)) = "modal.c,v 2.0 1994/05/19 02:01:20 dan Exp";
 #endif
 
 /*
