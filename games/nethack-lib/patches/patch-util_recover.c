$NetBSD: patch-util_recover.c,v 1.1 2020/01/08 16:55:13 pho Exp $

The directory where save files are located is defined as
VAR_PLAYGROUND. HACKDIR only has static files.

--- util/recover.c.orig	2020-01-08 16:49:06.924084164 +0000
+++ util/recover.c
@@ -121,9 +121,9 @@ char *argv[];
     }
 #endif /* SECURE && !VMS */
 
-#ifdef HACKDIR
+#ifdef VAR_PLAYGROUND
     if (!dir)
-        dir = HACKDIR;
+        dir = VAR_PLAYGROUND;
 #endif
 
 #ifdef AMIGA
