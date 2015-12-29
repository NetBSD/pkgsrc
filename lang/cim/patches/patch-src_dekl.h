$NetBSD: patch-src_dekl.h,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.

--- src/dekl.h.orig	2012-10-26 12:56:08.000000000 +0000
+++ src/dekl.h
@@ -189,9 +189,9 @@ struct BLOCK
 #define CCCPROC      8		/* Ekstern C-prosedyre */
 
 
-extern beginBlock ();
-extern endBlock ();
-extern regDecl ();
+void beginBlock (char kind);
+void endBlock (char *rtname, char codeclass);
+void regDecl (char *ident, char type, char kind, char categ);
 extern regInner ();
 extern struct DECL *newDecl ();
 extern struct BLOCK *firstclass ();
@@ -236,4 +236,8 @@ extern sameParam ();
 extern reinit ();
 extern initDecl ();
 
+void d1error (int errcode, char *name);
+void d2error (int errcode, struct DECL *rd1, struct DECL *rd2);
+void merror (int errcode, char *name);
+
 extern char yaccerror;
