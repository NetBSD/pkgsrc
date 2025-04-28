$NetBSD: patch-lib_error.c,v 1.1 2025/04/28 16:58:51 tnn Exp $

replace K&R prototypes

--- lib/error.c.orig	2025-04-28 16:40:26.017307162 +0000
+++ lib/error.c
@@ -73,7 +73,7 @@ extern char *program_name;
 
 # if HAVE_STRERROR
 #  ifndef strerror		/* On some systems, strerror is a macro */
-char *strerror ();
+char *strerror (int);
 #  endif
 # else
 static char *
