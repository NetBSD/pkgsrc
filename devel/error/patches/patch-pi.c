$NetBSD: patch-pi.c,v 1.1 2015/07/09 11:56:59 jperkin Exp $

Use nbcompat.

--- pi.c.orig	2005-05-10 20:49:29.000000000 +0000
+++ pi.c
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
 static char sccsid[] = "@(#)pi.c	8.1 (Berkeley) 6/6/93";
