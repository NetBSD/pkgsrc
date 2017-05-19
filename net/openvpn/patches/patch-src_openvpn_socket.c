$NetBSD: patch-src_openvpn_socket.c,v 1.3 2017/05/19 18:11:04 spz Exp $

Fix for systems without ipi_spec_dst in struct in_pktinfo.

--- src/openvpn/socket.c.orig	2017-05-11 10:34:40.000000000 +0000
+++ src/openvpn/socket.c
@@ -650,7 +650,7 @@ create_socket_udp (const unsigned int fl
   else if (flags & SF_USE_IP_PKTINFO)
     {
       int pad = 1;
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
       if (setsockopt (sd, SOL_IP, IP_PKTINFO,
 		      (void*)&pad, sizeof(pad)) < 0)
         msg(M_ERR, "UDP: failed setsockopt for IP_PKTINFO");
@@ -2263,7 +2263,7 @@ print_link_socket_actual_ex (const struc
 		  struct openvpn_sockaddr sa;
 		  CLEAR (sa);
 		  sa.addr.in4.sin_family = AF_INET;
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
 		  sa.addr.in4.sin_addr = act->pi.in4.ipi_spec_dst;
 		  if_indextoname(act->pi.in4.ipi_ifindex, ifname);
 #elif defined(IP_RECVDSTADDR)
@@ -2721,7 +2721,7 @@ link_socket_read_udp_posix_recvmsg (stru
 #error ENABLE_IP_PKTINFO is set without IP_PKTINFO xor IP_RECVDSTADDR (fix syshead.h)
 #endif
 	{
-#ifdef IP_PKTINFO
+#if defined(IP_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
 	  struct in_pktinfo *pkti = (struct in_pktinfo *) CMSG_DATA (cmsg);
 	  from->pi.in4.ipi_ifindex = pkti->ipi_ifindex;
 	  from->pi.in4.ipi_spec_dst = pkti->ipi_spec_dst;
@@ -2814,7 +2814,7 @@ link_socket_write_udp_posix_sendmsg (str
         mesg.msg_namelen = sizeof (struct sockaddr_in);
         mesg.msg_control = pktinfo_buf;
         mesg.msg_flags = 0;
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
         mesg.msg_controllen = CMSG_SPACE(sizeof (struct in_pktinfo));
         cmsg = CMSG_FIRSTHDR (&mesg);
         cmsg->cmsg_len = CMSG_LEN(sizeof (struct in_pktinfo));
