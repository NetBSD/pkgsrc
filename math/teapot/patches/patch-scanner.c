$NetBSD: patch-scanner.c,v 1.1 2026/03/19 08:50:23 nia Exp $

Fix implicit function declaration.

--- scanner.c.orig	2026-03-19 08:17:36.314937701 +0000
+++ scanner.c
@@ -25,6 +25,7 @@ extern double strtod(const char *nptr, c
 #include "main.h"
 #include "misc.h"
 #include "scanner.h"
+#include "utf8.h"
 /*}}}*/
 
 /* identcode  -- return number of identifier */ /*{{{*/
