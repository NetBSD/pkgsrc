$NetBSD: patch-chord.c,v 1.1 2026/03/19 14:51:40 nia Exp $

Modern GCC no longer likes implicit int.

--- chord.c.orig	2026-03-19 14:35:14.384006460 +0000
+++ chord.c
@@ -1124,6 +1124,7 @@ void read_chordrc()
 
 
 /* --------------------------------------------------------------------------------*/
+int
 main(argc, argv)
 int argc;
 char **argv;
