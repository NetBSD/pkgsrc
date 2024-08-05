$NetBSD: patch-setenv.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- setenv.c.orig	2024-08-05 14:16:36.914868052 +0000
+++ setenv.c
@@ -10,6 +10,7 @@
   * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.
   */
 
+#if 0 /* probably should be if ancient SunOS */
 #ifndef lint
 static char sccsid[] = "@(#) setenv.c 1.1 93/03/07 22:47:58";
 #endif
@@ -32,3 +33,4 @@ int     clobber;
     sprintf(cp, "%s=%s", name, value);
     return (putenv(cp));
 }
+#endif
