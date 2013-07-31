$NetBSD: patch-src_openvpn_socket.c,v 1.1 2013/07/31 06:53:21 adam Exp $

Fix for systems without ipi_spec_dst in struct in_pktinfo.

--- src/openvpn/socket.c.orig	2013-07-31 06:14:52.000000000 +0000
+++ src/openvpn/socket.c
@@ -652,7 +652,7 @@ create_socket_udp (const unsigned int fl
   else if (flags & SF_USE_IP_PKTINFO)
     {
       int pad = 1;
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
       if (setsockopt (sd, SOL_IP, IP_PKTINFO,
 		      (void*)&pad, sizeof(pad)) < 0)
         msg(M_ERR, "UDP: failed setsockopt for IP_PKTINFO");
@@ -2252,7 +2252,7 @@ print_link_socket_actual_ex (const struc
 		  struct openvpn_sockaddr sa;
 		  CLEAR (sa);
 		  sa.addr.in4.sin_family = AF_INET;
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
 		  sa.addr.in4.sin_addr = act->pi.in4.ipi_spec_dst;
 		  if_indextoname(act->pi.in4.ipi_ifindex, ifname);
 #elif defined(IP_RECVDSTADDR)
@@ -2649,7 +2649,7 @@ link_socket_read_tcp (struct link_socket
 struct openvpn_in4_pktinfo
 {
   struct cmsghdr cmsghdr;
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
   struct in_pktinfo pi4;
 #elif defined(IP_RECVDSTADDR)
   struct in_addr pi4;
@@ -2694,7 +2694,7 @@ link_socket_read_udp_posix_recvmsg (stru
       cmsg = CMSG_FIRSTHDR (&mesg);
       if (cmsg != NULL
 	  && CMSG_NXTHDR (&mesg, cmsg) == NULL
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
 	  && cmsg->cmsg_level == SOL_IP 
 	  && cmsg->cmsg_type == IP_PKTINFO
 #elif defined(IP_RECVDSTADDR)
@@ -2705,7 +2705,7 @@ link_socket_read_udp_posix_recvmsg (stru
 #endif
 	  && cmsg->cmsg_len >= sizeof (struct openvpn_in4_pktinfo))
 	{
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
 	  struct in_pktinfo *pkti = (struct in_pktinfo *) CMSG_DATA (cmsg);
 	  from->pi.in4.ipi_ifindex = pkti->ipi_ifindex;
 	  from->pi.in4.ipi_spec_dst = pkti->ipi_spec_dst;
@@ -2803,7 +2803,7 @@ link_socket_write_udp_posix_sendmsg (str
         mesg.msg_flags = 0;
         cmsg = CMSG_FIRSTHDR (&mesg);
         cmsg->cmsg_len = sizeof (struct openvpn_in4_pktinfo);
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
         cmsg->cmsg_level = SOL_IP;
         cmsg->cmsg_type = IP_PKTINFO;
 	{
