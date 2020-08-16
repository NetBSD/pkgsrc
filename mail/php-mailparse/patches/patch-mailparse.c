$NetBSD: patch-mailparse.c,v 1.1 2020/08/16 15:51:45 otis Exp $

Check for php mbstring extension properly.

--- mailparse.c.orig	2020-04-22 07:07:51.000000000 +0000
+++ mailparse.c
@@ -29,7 +29,7 @@
 #include "arginfo.h"
 
 /* just in case the config check doesn't enable mbstring automatically */
-#if !HAVE_MBSTRING
+#if !HAVE_MBSTRING && false
 #error The mailparse extension requires the mbstring extension!
 #endif
 
