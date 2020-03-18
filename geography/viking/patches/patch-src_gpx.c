$NetBSD: patch-src_gpx.c,v 1.3 2020/03/18 00:02:46 gdt Exp $

This is a build fix for SunOS.
\todo Explain why, and if the new __sun way is correct in general.
\todo File upstream.

--- src/gpx.c.orig	2020-01-30 08:34:43.000000000 +0000
+++ src/gpx.c
@@ -26,7 +26,12 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  *
  */
+
+#if defined(__sun)
+#define _XOPEN_SOURCE 600
+#else
 #define _XOPEN_SOURCE /* glibc2 needs this */
+#endif
 
 #include "gpx.h"
 #include "viking.h"
