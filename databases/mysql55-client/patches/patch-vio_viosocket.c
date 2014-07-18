$NetBSD: patch-vio_viosocket.c,v 1.1 2014/07/18 13:42:24 ryoon Exp $

--- vio/viosocket.c.orig	2014-01-14 08:16:26.000000000 +0000
+++ vio/viosocket.c
@@ -34,6 +34,12 @@
 # include <sys/filio.h>
 #endif
 
+#if defined(_SCO_DS)
+/* SCO OpenServer 5.0.7/3.2 has no SHUT_* macros. 
+   See http://osr507doc.sco.com/en/netguide/disockD.system_calls.html */
+#define SHUT_RDWR	2
+#endif
+
 int vio_errno(Vio *vio __attribute__((unused)))
 {
   return socket_errno;		/* On Win32 this mapped to WSAGetLastError() */
@@ -460,7 +466,12 @@ my_bool vio_get_normalized_ip_string(con
                                      char *ip_string,
                                      size_t ip_string_size)
 {
+/* SCO OpenServer 5.0.7/3.2 has no sockaddr_storage. */
+#if defined(_SCO_DS)
+  struct sockaddr_in norm_addr_storage;
+#else
   struct sockaddr_storage norm_addr_storage;
+#endif
   struct sockaddr *norm_addr= (struct sockaddr *) &norm_addr_storage;
   int norm_addr_length;
   int err_code;
@@ -504,7 +515,11 @@ my_bool vio_peer_addr(Vio *vio, char *ip
     */
     struct in_addr *ip4= &((struct sockaddr_in *) &(vio->remote))->sin_addr;
 
+/* SCO OpenServer 5.0.7/3.2 has no sockaddr_storage, and use sockaddr_in.
+   So there is no ss_family in sockaddr_in. */
+#if !defined(_SCO_DS)
     vio->remote.ss_family= AF_INET;
+#endif
     vio->addrLen= sizeof (struct sockaddr_in);
 
     ip4->s_addr= htonl(INADDR_LOOPBACK);
@@ -519,7 +534,12 @@ my_bool vio_peer_addr(Vio *vio, char *ip
     int err_code;
     char port_buffer[NI_MAXSERV];
 
+/* SCO OpenServer 5.0.7/3.2 has no sockaddr_storage. */
+#if defined(_SCO_DS)
+    struct sockaddr_in addr_storage;
+#else
     struct sockaddr_storage addr_storage;
+#endif
     struct sockaddr *addr= (struct sockaddr *) &addr_storage;
     size_socket addr_length= sizeof (addr_storage);
 
