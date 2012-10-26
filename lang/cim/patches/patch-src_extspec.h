$NetBSD: patch-src_extspec.h,v 1.1 2012/10/26 20:37:15 joerg Exp $

--- src/extspec.h.orig	2012-10-26 13:03:54.000000000 +0000
+++ src/extspec.h
@@ -28,7 +28,7 @@ void gettimestamp ();
 void initExtspec ();
 extern char *directive_timestamp;
 extern char *timestamp;
-extern lesinn_external_spec ();
+void lesinn_external_spec (char *ident, char *filename, char kind);
 extern more_modules ();
 extern struct stamp *first_stamp;
 extern skrivut_external_spec ();
