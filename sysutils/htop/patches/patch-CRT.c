$NetBSD: patch-CRT.c,v 1.2 2012/03/21 18:28:40 drochner Exp $

--- CRT.c.orig	2011-12-26 21:52:55.000000000 +0000
+++ CRT.c
@@ -120,7 +120,9 @@ int CRT_cursorX = 0;
 
 char* CRT_termType;
 
+#ifdef HAVE_EXECINFO_H
 void *backtraceArray[128];
+#endif
 
 static void CRT_handleSIGSEGV(int sgn) {
    (void) sgn;
