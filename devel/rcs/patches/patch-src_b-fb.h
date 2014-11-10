$NetBSD: patch-src_b-fb.h,v 1.1 2014/11/10 18:05:45 joerg Exp $

--- src/b-fb.h.orig	2014-11-10 12:51:30.000000000 +0000
+++ src/b-fb.h
@@ -21,9 +21,9 @@
 */
 
 extern int change_mode (int fd, mode_t mode);
-extern void Ierror (void) exiting;
+extern exiting void Ierror (void);
 extern void testIerror (FILE *f);
-extern void Oerror (void) exiting;
+extern exiting void Oerror (void);
 extern void testOerror (FILE *o);
 extern FILE *fopen_safer (char const *filename, char const *type);
 extern void Ozclose (FILE **p);
