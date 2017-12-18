$NetBSD: patch-regress_nonrandomopen.c,v 1.1 2017/12/18 16:48:20 jperkin Exp $

Work around redefine_extname in SunOS headers.

--- regress/nonrandomopen.c.orig	2017-10-06 11:00:00.000000000 +0000
+++ regress/nonrandomopen.c
@@ -31,6 +31,11 @@
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
+#if defined(__sun)
+#pragma redefine_extname open open
+#pragma redefine_extname open64 open64
+#endif
+
 #include <fcntl.h>
 #include <stdarg.h>
 #include <stdlib.h>
