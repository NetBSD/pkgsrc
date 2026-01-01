$NetBSD: patch-src_fping.c,v 1.5 2026/01/01 09:24:15 adam Exp $

IP_RECVTOS is not available on NetBSD.

--- src/fping.c.orig	2026-01-01 09:15:00.800627716 +0000
+++ src/fping.c
@@ -712,11 +712,13 @@ int main(int argc, char **argv)
                 ping_data_size = ICMP_TIMESTAMP_DATA_SIZE;
             } else if (strstr(optparse_state.optlongname, "print-tos") != NULL) {
                 print_tos_flag = 1;
+#if defined(IP_RECVTOS)
                 if (socket4 >= 0 && (socktype4 == SOCK_DGRAM)) {
                     if (setsockopt(socket4, IPPROTO_IP, IP_RECVTOS, &sock_opt_on, sizeof(sock_opt_on))) {
                         perror("setsockopt IP_RECVTOS");
                     }
                 }
+#endif
 #if defined(IPV6) && defined(IPV6_RECVTCLASS)
                 if (socket6 >= 0) {
                     if (setsockopt(socket6, IPPROTO_IPV6, IPV6_RECVTCLASS, &sock_opt_on, sizeof(sock_opt_on))) {
