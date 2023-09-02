$NetBSD: patch-ioev.h,v 1.1 2023/09/02 21:32:11 vins Exp $

Add missing includes for sockaddr_in structure.

--- ioev.h.orig	2019-11-14 17:40:26.000000000 +0000
+++ ioev.h
@@ -15,6 +15,11 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#ifndef _NETINET_IN_H_
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 enum {
 	IO_CONNECTED = 0, 	/* connection successful	*/
 	IO_TLSREADY,		/* TLS started successfully	*/
