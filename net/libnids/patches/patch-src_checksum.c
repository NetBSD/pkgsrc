$NetBSD: patch-src_checksum.c,v 1.1 2015/01/26 15:52:18 sevan Exp $

Symbols for inline functions are not exported when built with clang
Bug #2 file in tracker
https://sourceforge.net/p/libnids/bugs/2/

--- src/checksum.c.orig	2015-01-25 04:30:20.000000000 +0000
+++ src/checksum.c
@@ -120,7 +120,7 @@ csum_partial(const u_char * buff, int le
   By Jorge Cwik <jorge@laser.satlink.net>, adapted for linux by Arnt
   Gulbrandsen.
 */
-inline u_short ip_fast_csum(u_char * iph, u_int ihl)
+u_short ip_fast_csum(u_char * iph, u_int ihl)
 {
   u_int sum;
   if (dontchksum(((struct ip*)iph)->ip_src.s_addr))
@@ -191,13 +191,13 @@ csum_tcpudp_magic(u_int saddr, u_int dad
   this routine is used for miscellaneous IP-like checksums, mainly in
   icmp.c
 */
-inline u_short
+u_short
 ip_compute_csum(u_char * buff, int len)
 {
   return (csum_fold(csum_partial(buff, len, 0)));
 }
 
-inline u_short
+u_short
 my_tcp_check(struct tcphdr *th, int len, u_int saddr, u_int daddr)
 {
   if (dontchksum(saddr))
@@ -205,7 +205,7 @@ my_tcp_check(struct tcphdr *th, int len,
   return csum_tcpudp_magic(saddr, daddr, len, IPPROTO_TCP,
 			   csum_partial((u_char *)th, len, 0));
 }
-inline u_short
+u_short
 my_udp_check(void *u, int len, u_int saddr, u_int daddr)
 {
   if (dontchksum(saddr))
