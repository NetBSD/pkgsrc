$NetBSD: patch-def.h,v 1.1 2013/03/28 21:24:54 joerg Exp $

--- def.h.orig	2013-03-28 19:10:49.000000000 +0000
+++ def.h
@@ -485,8 +485,8 @@ extern VOID putline pro((int, int, unsig
 #endif
 extern int vtputs pro((char *));
 extern int kdispbufcode pro((BUFFER *));
-extern int ttinsl pro((int, int, int));
-extern int ttdell pro((int, int, int));
+extern void ttinsl pro((int, int, int));
+extern void ttdell pro((int, int, int));
 extern int fepmode_off pro((void));
 extern int getkey pro((int));
 extern VOID ungetkey pro((int));
