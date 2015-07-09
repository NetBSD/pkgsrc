$NetBSD: patch-touch.c,v 1.1 2015/07/09 11:56:59 jperkin Exp $

Use nbcompat.

--- touch.c.orig	2005-05-10 20:48:24.000000000 +0000
+++ touch.c
@@ -29,7 +29,12 @@
  * SUCH DAMAGE.
  */
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat.h>
+#include <nbcompat/cdefs.h>
+#else
 #include <sys/cdefs.h>
+#endif
 #ifndef lint
 #if 0
 static char sccsid[] = "@(#)touch.c	8.1 (Berkeley) 6/6/93";
