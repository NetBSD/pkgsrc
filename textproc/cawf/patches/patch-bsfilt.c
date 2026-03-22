$NetBSD: patch-bsfilt.c,v 1.1 2026/03/22 10:31:53 nia Exp $

Modern GCC no longer likes implicit int.

--- bsfilt.c.orig	2026-03-22 10:00:27.919793184 +0000
+++ bsfilt.c
@@ -59,6 +59,7 @@ int Ulx = 0;				/* underline buffer inde
 
 _PROTOTYPE(void Putchar,(int ch));
 
+int
 main(argc, argv)
 	int argc;
 	char *argv[];
