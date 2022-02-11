$NetBSD: patch-services_listen__dnsport.c,v 1.2 2022/02/11 09:28:16 he Exp $

Apply fix from
https://github.com/NLnetLabs/unbound/commit/5f724da8c57c5a6bf1d589b6651daec2dc39a9d1
Paraphrased:
Fix plain DNS-over-TCP so that it doesn't try to use TLS when
TLS is also configured elsewhere.

--- services/listen_dnsport.c.orig	2022-02-10 07:57:36.000000000 +0000
+++ services/listen_dnsport.c
@@ -1369,17 +1369,17 @@ listen_create(struct comm_base* base, st
 	while(ports) {
 		struct comm_point* cp = NULL;
 		if(ports->ftype == listen_type_udp ||
-		   ports->ftype == listen_type_udp_dnscrypt)
+		   ports->ftype == listen_type_udp_dnscrypt) {
 			cp = comm_point_create_udp(base, ports->fd,
 				front->udp_buff, cb, cb_arg, ports->socket);
-		else if(ports->ftype == listen_type_tcp ||
-				ports->ftype == listen_type_tcp_dnscrypt)
+		} else if(ports->ftype == listen_type_tcp ||
+				ports->ftype == listen_type_tcp_dnscrypt) {
 			cp = comm_point_create_tcp(base, ports->fd,
 				tcp_accept_count, tcp_idle_timeout,
 				harden_large_queries, 0, NULL,
 				tcp_conn_limit, bufsize, front->udp_buff,
 				ports->ftype, cb, cb_arg, ports->socket);
-		else if(ports->ftype == listen_type_ssl ||
+		} else if(ports->ftype == listen_type_ssl ||
 			ports->ftype == listen_type_http) {
 			cp = comm_point_create_tcp(base, ports->fd,
 				tcp_accept_count, tcp_idle_timeout,
@@ -1410,15 +1410,22 @@ listen_create(struct comm_base* base, st
 #endif
 			}
 		} else if(ports->ftype == listen_type_udpancil ||
-				  ports->ftype == listen_type_udpancil_dnscrypt)
+				  ports->ftype == listen_type_udpancil_dnscrypt) {
 			cp = comm_point_create_udp_ancil(base, ports->fd,
 				front->udp_buff, cb, cb_arg, ports->socket);
+		}
 		if(!cp) {
 			log_err("can't create commpoint");
 			listen_delete(front);
 			return NULL;
 		}
-		if(http_notls && ports->ftype == listen_type_http)
+		if((http_notls && ports->ftype == listen_type_http) ||
+		    (ports->ftype == listen_type_tcp) ||
+		    (ports->ftype == listen_type_udp) ||
+		    (ports->ftype == listen_type_udpancil) ||
+		    (ports->ftype == listen_type_tcp_dnscrypt) ||
+		    (ports->ftype == listen_type_udp_dnscrypt) ||
+		    (ports->ftype == listen_type_udpancil_dnscrypt))
 			cp->ssl = NULL;
 		else
 			cp->ssl = sslctx;
