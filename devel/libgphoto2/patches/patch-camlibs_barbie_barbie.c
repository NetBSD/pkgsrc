$NetBSD: patch-camlibs_barbie_barbie.c,v 1.1 2018/01/31 10:53:40 jperkin Exp $

Set _POSIX_C_SOURCE correctly.

--- camlibs/barbie/barbie.c.orig	2014-06-04 18:19:35.000000000 +0000
+++ camlibs/barbie/barbie.c
@@ -21,7 +21,9 @@
  * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  * Boston, MA  02110-1301  USA
  */
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_C_SOURCE 199309L
+#endif
 
 #include "config.h"
 
