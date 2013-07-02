$NetBSD: patch-network.c,v 1.1 2013/07/02 00:22:17 christos Exp $

Handle not having IP_PKTINFO
Don't set control buf if controllen == 0

--- network.c.orig	2013-06-17 06:17:24.000000000 -0400
+++ network.c	2013-06-26 17:15:55.000000000 -0400
@@ -85,14 +85,15 @@
 
 	    gconfig.ipsecsaref=0;
     }
-    
+#else
+	l2tp_log(LOG_INFO, "No attempt being made to use IPsec SAref's since we're not on a Linux machine.\n");
+
+#endif    
+#ifdef IP_PKTINFO
     arg=1;
     if(setsockopt(server_socket, IPPROTO_IP, IP_PKTINFO, (char*)&arg, sizeof(arg)) != 0) {
 	    l2tp_log(LOG_CRIT, "setsockopt IP_PKTINFO: %s\n", strerror(errno));
     }
-#else
-	l2tp_log(LOG_INFO, "No attempt being made to use IPsec SAref's since we're not on a Linux machine.\n");
-
 #endif
 
 #ifdef USE_KERNEL
@@ -271,12 +272,18 @@
 void udp_xmit (struct buffer *buf, struct tunnel *t)
 {
     struct cmsghdr *cmsg;
-    char cbuf[CMSG_SPACE(sizeof (unsigned int) + sizeof (struct in_pktinfo))];
+    char cbuf[CMSG_SPACE(sizeof (unsigned int)
+#ifdef IP_PKTINFO
+    + sizeof (struct in_pktinfo)
+#endif
+    )];
     unsigned int *refp;
     struct msghdr msgh;
     int err;
     struct iovec iov;
+#ifdef IP_PKTINFO
     struct in_pktinfo *pktinfo;
+#endif
     int finallen;
     
     /*
@@ -303,7 +310,7 @@
 	
 	finallen = cmsg->cmsg_len;
     }
-    
+#ifdef IP_PKTINFO    
     if (t->my_addr.ipi_addr.s_addr){
 
 	if ( ! cmsg) {
@@ -322,7 +329,9 @@
 	
 	finallen += cmsg->cmsg_len;
     }
-    
+#endif
+    if (finallen == 0)
+	msgh.msg_control = NULL;
     msgh.msg_controllen = finallen;
     
     iov.iov_base = buf->start;
@@ -417,7 +426,9 @@
      * our network socket.  Control handling is no longer done here.
      */
     struct sockaddr_in from;
+#ifdef IP_PKTINFO
     struct in_pktinfo to;
+#endif
     unsigned int fromlen;
     int tunnel, call;           /* Tunnel and call */
     int recvsize;               /* Length of data received */
@@ -497,7 +508,9 @@
             buf->len -= PAYLOAD_BUF;
 
 	    memset(&from, 0, sizeof(from));
+#ifdef IP_PKTINFO
 	    memset(&to,   0, sizeof(to));
+#endif
 	    
 	    fromlen = sizeof(from);
 	    
@@ -548,13 +561,16 @@
 		for (cmsg = CMSG_FIRSTHDR(&msgh);
 			cmsg != NULL;
 			cmsg = CMSG_NXTHDR(&msgh,cmsg)) {
+#ifdef IP_PKTINFO
 			/* extract destination(our) addr */
 			if (cmsg->cmsg_level == IPPROTO_IP && cmsg->cmsg_type == IP_PKTINFO) {
 				struct in_pktinfo* pktInfo = ((struct in_pktinfo*)CMSG_DATA(cmsg));
 				to = *pktInfo;
+				continue;
 			}
+#endif
 			/* extract IPsec info out */
-			else if (gconfig.ipsecsaref && cmsg->cmsg_level == IPPROTO_IP
+			if (gconfig.ipsecsaref && cmsg->cmsg_level == IPPROTO_IP
 			&& cmsg->cmsg_type == gconfig.sarefnum) {
 				unsigned int *refp;
 				
@@ -618,9 +634,11 @@
 	    }
 	    else
 	    {
+#ifdef IP_PKTINFO
 		if (c->container) {
 			c->container->my_addr = to;
 		}
+#endif
 
 		buf->peer = from;
 		/* Handle the packet */
