$NetBSD: patch-network.c,v 1.2 2014/02/14 22:06:39 christos Exp $

Handle not having IP_PKTINFO
Handle not having SO_NO_CHECK
Don't set control buf if controllen == 0
Fix reversed PLBIT test?

--- network.c.orig	2014-01-16 17:02:04.000000000 -0500
+++ network.c	2014-02-14 16:00:07.000000000 -0500
@@ -85,24 +85,26 @@
 
 	    gconfig.ipsecsaref=0;
     }
-    
-    arg=1;
-    if(setsockopt(server_socket, IPPROTO_IP, IP_PKTINFO, (char*)&arg, sizeof(arg)) != 0) {
-	    l2tp_log(LOG_CRIT, "setsockopt IP_PKTINFO: %s\n", strerror(errno));
-    }
 #else
     {
 	l2tp_log(LOG_INFO, "No attempt being made to use IPsec SAref's since we're not on a Linux machine.\n");
     }
-
+#endif
+#ifdef IP_PKTINFO    
+    arg=1;
+    if(setsockopt(server_socket, IPPROTO_IP, IP_PKTINFO, (char*)&arg, sizeof(arg)) != 0) {
+	    l2tp_log(LOG_CRIT, "setsockopt IP_PKTINFO: %s\n", strerror(errno));
+    }
 #endif
 
     /* turn off UDP checksums */
+#ifdef SO_NO_CHECK
     arg=1;
     if (setsockopt(server_socket, SOL_SOCKET, SO_NO_CHECK , (void*)&arg,
                    sizeof(arg)) ==-1) {
       l2tp_log(LOG_INFO, "unable to turn off UDP checksums");
     }
+#endif
 
 #ifdef USE_KERNEL
     if (gconfig.forceuserspace)
@@ -143,7 +145,7 @@
      */
 
     struct payload_hdr *p = (struct payload_hdr *) buf;
-    if (PLBIT (p->ver))
+    if (!PLBIT (p->ver))
     {
         *tunnel = p->tid;
         *call = p->cid;
@@ -280,12 +282,18 @@
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
@@ -312,7 +320,7 @@
 	
 	finallen = cmsg->cmsg_len;
     }
-    
+#ifdef IP_PKTINFO    
     if (t->my_addr.ipi_addr.s_addr){
 
 	if ( ! cmsg) {
@@ -331,7 +339,9 @@
 	
 	finallen += cmsg->cmsg_len;
     }
-    
+#endif
+    if (finallen == 0)
+	msgh.msg_control = NULL;
     msgh.msg_controllen = finallen;
     
     iov.iov_base = buf->start;
@@ -426,7 +436,9 @@
      * our network socket.  Control handling is no longer done here.
      */
     struct sockaddr_in from;
+#ifdef IP_PKTINFO
     struct in_pktinfo to;
+#endif
     unsigned int fromlen;
     int tunnel, call;           /* Tunnel and call */
     int recvsize;               /* Length of data received */
@@ -506,7 +518,9 @@
             buf->len -= PAYLOAD_BUF;
 
 	    memset(&from, 0, sizeof(from));
+#ifdef IP_PKTINFO
 	    memset(&to,   0, sizeof(to));
+#endif
 	    
 	    fromlen = sizeof(from);
 	    
@@ -557,13 +571,16 @@
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
 				
@@ -627,9 +644,11 @@
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
