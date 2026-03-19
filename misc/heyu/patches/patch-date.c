$NetBSD: patch-date.c,v 1.1 2026/03/19 14:55:21 nia Exp $

Modern GCC no longer likes implicit int. ANSIfy.

--- date.c.orig	2026-03-19 14:43:58.416133889 +0000
+++ date.c
@@ -39,8 +39,7 @@ extern int
 
 /* ARGSUSED */
 
-int c_date(argc, argv)
-char *argv[];
+int c_date(int argc, char *argv[])
 {
     int  today;
     struct tm *tp;
