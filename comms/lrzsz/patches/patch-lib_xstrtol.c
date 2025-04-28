$NetBSD: patch-lib_xstrtol.c,v 1.1 2025/04/28 16:58:51 tnn Exp $

replace K&R prototypes

--- lib/xstrtol.c.orig	2025-04-28 16:46:42.603541382 +0000
+++ lib/xstrtol.c
@@ -65,7 +65,7 @@ extern int errno;
 	}								\
       while (0)
 
-__unsigned long int __strtol ();
+__unsigned long int __strtol (const char*, char **, int);
 
 /* FIXME: comment.  */
 
