$NetBSD: patch-ntlm_client-ntlm.c,v 1.1 2018/07/30 13:38:08 jperkin Exp $

Set _XOPEN_SOURCE correctly.

--- ntlm/client-ntlm.c.orig	2010-08-08 15:45:56.000000000 +0000
+++ ntlm/client-ntlm.c
@@ -21,7 +21,11 @@
  *  License along with this library; if not, write to the Free Software
  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE	500
+#else
+#define _XOPEN_SOURCE	600
+#endif
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
