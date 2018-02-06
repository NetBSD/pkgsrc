$NetBSD: patch-src_fr-command-unarchiver.c,v 1.1 2018/02/06 09:59:38 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- src/fr-command-unarchiver.c.orig	2016-04-07 11:37:58.000000000 +0000
+++ src/fr-command-unarchiver.c
@@ -19,7 +19,9 @@
  *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE       /* See feature_test_macros(7) */
+#endif
 #include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
