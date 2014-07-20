$NetBSD: patch-src_openvpn_socket.c,v 1.2 2014/07/20 17:43:29 adam Exp $

Fix for systems without ipi_spec_dst in struct in_pktinfo.

--- src/openvpn/socket.c.orig	2014-05-01 11:12:22.000000000 +0000
+++ src/openvpn/socket.c
@@ -654,7 +654,7 @@ create_socket_udp (const unsigned int fl
   else if (flags & SF_USE_IP_PKTINFO)
     {
       int pad = 1;
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
       if (setsockopt (sd, SOL_IP, IP_PKTINFO,
 		      (void*)&pad, sizeof(pad)) < 0)
         msg(M_ERR, "UDP: failed setsockopt for IP_PKTINFO");
@@ -2254,7 +2254,7 @@ print_link_socket_actual_ex (const struc
 		  struct openvpn_sockaddr sa;
 		  CLEAR (sa);
 		  sa.addr.in4.sin_family = AF_INET;
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
 		  sa.addr.in4.sin_addr = act->pi.in4.ipi_spec_dst;
 		  if_indextoname(act->pi.in4.ipi_ifindex, ifname);
 #elif defined(IP_RECVDSTADDR)
@@ -2651,7 +2651,7 @@ link_socket_read_tcp (struct link_socket
 struct openvpn_in4_pktinfo
 {
   struct cmsghdr cmsghdr;
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
   struct in_pktinfo pi4;
 #elif defined(IP_RECVDSTADDR)
   struct in_addr pi4;
@@ -2696,7 +2696,7 @@ link_socket_read_udp_posix_recvmsg (stru
       cmsg = CMSG_FIRSTHDR (&mesg);
       if (cmsg != NULL
 	  && CMSG_NXTHDR (&mesg, cmsg) == NULL
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
 	  && cmsg->cmsg_level == SOL_IP 
 	  && cmsg->cmsg_type == IP_PKTINFO
 #elif defined(IP_RECVDSTADDR)
@@ -2707,7 +2707,7 @@ link_socket_read_udp_posix_recvmsg (stru
 #endif
 	  && cmsg->cmsg_len >= sizeof (struct openvpn_in4_pktinfo))
 	{
-#ifdef IP_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
 	  struct in_pktinfo *pkti = (struct in_pktinfo *) CMSG_DATA (cmsg);
 	  from->pi.in4.ipi_ifindex = pkti->ipi_ifindex;
 	  from->pi.in4.ipi_spec_dst = pkti->ipi_spec_dst;
@@ -2802,7 +2802,7 @@ link_socket_write_udp_posix_sendmsg (str
         mesg.msg_namelen = sizeof (struct sockaddr_in);
         mesg.msg_control = &opi;
         mesg.msg_flags = 0;
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
         mesg.msg_controllen = sizeof (struct openvpn_in4_pktinfo);
         cmsg = CMSG_FIRSTHDR (&mesg);
         cmsg->cmsg_len = sizeof (struct openvpn_in4_pktinfo);
