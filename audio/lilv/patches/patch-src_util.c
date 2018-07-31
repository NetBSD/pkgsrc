$NetBSD: patch-src_util.c,v 1.1 2018/07/31 15:35:38 jperkin Exp $

Set _POSIX_C_SOURCE correctly.

--- src/util.c.orig	2014-08-08 14:40:03.000000000 +0000
+++ src/util.c
@@ -14,7 +14,9 @@
   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_C_SOURCE 1  /* for fileno */
+#endif
 #define _BSD_SOURCE     1  /* for realpath, symlink */
 
 #ifdef __APPLE__
