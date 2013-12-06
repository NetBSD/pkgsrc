$NetBSD: patch-src_srun_libsrun_debugger.c,v 1.1 2013/12/06 06:05:30 asau Exp $

--- src/srun/libsrun/debugger.c.orig	2013-11-04 21:19:15.000000000 +0000
+++ src/srun/libsrun/debugger.c
@@ -38,7 +38,7 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <signal.h>
 #endif
 
