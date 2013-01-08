$NetBSD: patch-rcfile.c,v 1.1 2013/01/08 10:16:43 wiz Exp $

At least NetBSD doesn't define unix.

--- rcfile.c.orig	2006-05-18 08:27:43.000000000 +0000
+++ rcfile.c
@@ -5,10 +5,10 @@
 #include <string.h>
 #include <ctype.h>
 
-#if defined(unix) && !defined(GO32)
-#define RCNAME ".tweakrc"
-#elif defined(MSDOS)
+#if defined(MSDOS) || defined(GO32)
 #define RCNAME "tweak.rc"
+#else
+#define RCNAME ".tweakrc"
 #endif
 
 static char *default_rc[] = {
