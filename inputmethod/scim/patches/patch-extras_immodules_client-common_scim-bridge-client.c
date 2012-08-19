$NetBSD: patch-extras_immodules_client-common_scim-bridge-client.c,v 1.1 2012/08/19 08:09:08 obache Exp $

--- extras/immodules/client-common/scim-bridge-client.c.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/client-common/scim-bridge-client.c
@@ -38,6 +38,11 @@
 #include "scim-bridge-path.h"
 #include "scim-bridge-string.h"
 
+#ifndef SUN_LEN
+#define SUN_LEN(su) \
+	    (sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
+#endif
+
 /* Private data type */
 typedef struct _IMContextListElement
 {
@@ -1080,7 +1085,7 @@ retval_t scim_bridge_client_open_messeng
         socket_addr.sun_family = AF_UNIX;
         strcpy (socket_addr.sun_path, scim_bridge_path_get_socket ());
 
-        if (connect (socket_fd, (struct sockaddr*)&socket_addr, sizeof (socket_addr.sun_family) + strlen (socket_addr.sun_path))) {
+        if (connect (socket_fd, (struct sockaddr*)&socket_addr, SUN_LEN(&socket_addr))) {
             if (i == 5 && launch_agent ()) {
                 scim_bridge_perrorln ("Cannot launch the agent");
                 return RETVAL_FAILED;
