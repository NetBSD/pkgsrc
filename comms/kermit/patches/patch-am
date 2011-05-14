$NetBSD: patch-am,v 1.1 2011/05/14 19:27:53 hans Exp $

--- ckuusx.c.orig	2004-03-14 18:13:23.000000000 +0100
+++ ckuusx.c	2009-12-26 23:23:19.652637206 +0100
@@ -70,6 +70,9 @@ _PROTOTYP(char * os2_gethostname, (void)
 #ifdef BSD44
 #include <errno.h>
 #endif /* BSD44 */
+#ifdef SOLARIS
+#include <errno.h>
+#endif
 
 extern xx_strp xxstring;
 
