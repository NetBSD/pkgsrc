$NetBSD: patch-src_plugins_lan_lan.c,v 1.2 2017/02/14 21:20:48 joerg Exp $

--- src/plugins/lan/lan.c.orig	2009-02-25 20:38:53.000000000 +0000
+++ src/plugins/lan/lan.c
@@ -30,11 +30,12 @@
  * EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
  */
 
+#include <sys/types.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <inttypes.h>
 #include <string.h>
-#include <sys/types.h>
+#include <sys/time.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -1071,7 +1072,7 @@ uint8_t * ipmi_lan_build_sol_msg(struct 
 	msg = malloc(len);
 	if (msg == NULL) {
 		lprintf(LOG_ERR, "ipmitool: malloc failure");
-		return;
+		return NULL;
 	}
 	memset(msg, 0, len);
 
