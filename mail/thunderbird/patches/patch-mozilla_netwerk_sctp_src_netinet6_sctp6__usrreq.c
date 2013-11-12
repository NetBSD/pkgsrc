$NetBSD: patch-mozilla_netwerk_sctp_src_netinet6_sctp6__usrreq.c,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/netwerk/sctp/src/netinet6/sctp6_usrreq.c.orig	2013-10-23 22:09:15.000000000 +0000
+++ mozilla/netwerk/sctp/src/netinet6/sctp6_usrreq.c
@@ -459,6 +459,8 @@ sctp6_notify(struct sctp_inpcb *inp,
 	    (icmph->icmp6_code == ICMP_UNREACH_HOST_PROHIB) ||
 #ifdef __Panda__
             (icmph->icmp6_code == ICMP_UNREACH_ADMIN)) {
+#elif defined(__Userspace_os_NetBSD)
+            (icmph->icmp6_code == ICMP_UNREACH_ADMIN_PROHIBIT)) {
 #else
             (icmph->icmp6_code == ICMP_UNREACH_FILTER_PROHIB)) {
 #endif
