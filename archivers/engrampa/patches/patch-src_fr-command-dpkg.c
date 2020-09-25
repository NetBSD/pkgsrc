$NetBSD: patch-src_fr-command-dpkg.c,v 1.1 2020/09/25 09:02:58 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- src/fr-command-dpkg.c.orig	2020-02-10 11:05:03.000000000 +0000
+++ src/fr-command-dpkg.c
@@ -20,7 +20,9 @@
  *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
  */
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE /* strptime */
+#endif
 
 #include <config.h>
 #include <stdlib.h>
