$NetBSD: patch-src_util.c,v 1.2 2019/01/02 20:31:48 bsiegert Exp $

Set _POSIX_C_SOURCE correctly.

--- src/util.c.orig	2018-07-21 08:10:18.000000000 +0000
+++ src/util.c
@@ -14,7 +14,9 @@
   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
 
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_C_SOURCE 200809L  /* for fileno */
+#endif
 #define _BSD_SOURCE     1        /* for realpath, symlink */
 #define _DEFAULT_SOURCE 1        /* for realpath, symlink */
 
