$NetBSD: patch-src_dpni20.c,v 1.1 2013/10/17 15:41:10 ryoon Exp $

http://www.falu.nl/~rhialto/klh-diffs2

--- src/dpni20.c.orig	2003-02-23 10:07:50.000000000 +0000
+++ src/dpni20.c
@@ -170,4 +170,5 @@ The following general situations are pos
 #endif
 
+
 /* Globals */
 
@@ -433,4 +434,6 @@ main(int argc, char **argv)
     tentoeth(dpni);		/* Parent process handles output to net */
 
+    osn_pfdeinit();
+
     return 1;			/* Never returns, but placate compiler */
 }
@@ -499,4 +502,5 @@ void net_init(register struct dpni20_s *
   }
 
+
     /* Now set any return info values in shared struct.
     */
@@ -997,5 +1001,5 @@ pfshow(struct OSN_PFSTRUCT *pf)
 /* LNX packetfilter initialization */
 
-#if KLH10_NET_LNX
+#if KLH10_NET_LNX || KLH10_NET_TAP_BRIDGE
 
 /*
@@ -1093,4 +1097,8 @@ int lnx_filter(register struct dpni20_s 
 void eth_adrset(register struct dpni20_s *dpni)
 {
+#if OSN_USE_IPONLY
+    dbprintln("\"%s\" multicast table ignored - IP-only interface",
+		  dpni->dpni_ifnam);
+#else
     unsigned char rdea[ETHER_ADRSIZ];
     char old[OSN_EASTRSIZ];
@@ -1158,4 +1166,5 @@ void eth_adrset(register struct dpni20_s
     }
 
+#endif
     /* Assume succeeded since call succeeded, and clobber our address! */
     memcpy(dpni->dpni_eth, dpni->dpni_rqeth, ETHER_ADRSIZ);
@@ -1176,4 +1185,8 @@ void eth_adrset(register struct dpni20_s
 void eth_mcatset(register struct dpni20_s *dpni)
 {
+#if OSN_USE_IPONLY
+    dbprintln("\"%s\" multicast table ignored - IP-only interface",
+		  dpni->dpni_ifnam);
+#else
     ossock_t s;
     int i, n, j;
@@ -1250,4 +1263,5 @@ void eth_mcatset(register struct dpni20_
     nmcats = n;
     memcpy(ethmcat[0], dpni->dpni_mcat[0], (n * 6));
+#endif
 }
 
@@ -1362,5 +1376,7 @@ int arp_myreply(register unsigned char *
     if (swstatus) {
 	char ipstr[OSN_IPSTRSIZ];
-	dbprintln("ARP MyReply %s", ip_adrsprint(ipstr, ife->ife_ipchr));
+	char ethstr[OSN_EASTRSIZ];
+	dbprintln("ARP MyReply %s %s", ip_adrsprint(ipstr, ife->ife_ipchr),
+			eth_adrsprint(ethstr, ife->ife_ea));
     }
 
@@ -1373,4 +1389,7 @@ int arp_myreply(register unsigned char *
     }
 #else
+    /* XXX
+     * Why is this sent to the packet filter (= host) and not to the -10?????
+     */
     (void)write(pffd, pktbuf, sizeof(pktbuf));
 #endif
@@ -1442,5 +1461,5 @@ void ethtoten(register struct dpni20_s *
 	/* Else cnt must be -1 as call failed */
     }
-#elif KLH10_NET_NIT || KLH10_NET_PFLT || KLH10_NET_LNX
+#elif KLH10_NET_NIT || KLH10_NET_PFLT || KLH10_NET_LNX || KLH10_NET_TAP_BRIDGE
 	cnt = read(pffd, buff, max);
 #elif KLH10_NET_BPF
@@ -1500,15 +1519,18 @@ void ethtoten(register struct dpni20_s *
 		dbprint("Read=%d", cnt);
 	}
-#if KLH10_NET_LNX
+#if KLH10_NET_LNX || KLH10_NET_TAP_BRIDGE
 	/* Linux has no packet filtering, thus must apply manual check to
 	   each and every packet read, unless dedicated.  Ugh!
 	*/
-	if (!dpni->dpni_dedic) {
+	if (KLH10_NET_TAP_BRIDGE || !dpni->dpni_dedic) {
 	    /* Sharing interface.  Check for IP, DECNET, 802.3 */
-	    if (!lnx_filter(dpni, buff, cnt))
+	    if (!lnx_filter(dpni, buff, cnt)) {
+		if (DBGFLG)
+		    dbprint("Dropped");
 		continue;		/* Drop packet, continue reading */
+	    }
 	}
 #endif /* KLH10_NET_LNX */
-#if KLH10_NET_NIT || KLH10_NET_DLPI || KLH10_NET_PFLT || KLH10_NET_LNX
+#if KLH10_NET_NIT || KLH10_NET_DLPI || KLH10_NET_PFLT || KLH10_NET_LNX || KLH10_NET_TAP_BRIDGE
 #if 0
 	if (DBGFLG)
@@ -1522,5 +1544,5 @@ void ethtoten(register struct dpni20_s *
 	    dbprint("sent RPKT");
 
-#endif /* KLH10_NET_NIT || KLH10_NET_DLPI || KLH10_NET_PFLT || KLH10_NET_LNX */
+#endif /* KLH10_NET_NIT || KLH10_NET_DLPI || KLH10_NET_PFLT || KLH10_NET_LNX || NET_TAP_BRIDGE */
 
 #if KLH10_NET_BPF
@@ -1595,5 +1617,9 @@ void tentoeth(register struct dpni20_s *
     ** at least one entry in our table of host's IP interfaces.
     */
+#if KLH10_NET_TAP_BRIDGE
+    doarpchk = 0;
+#else
     doarpchk = (dpni->dpni_doarp & DPNI_ARPF_OCHK) && (osn_nifents() > 0);
+#endif
 
     dpx = dp_dpxto(&dp);		/* Get ptr to "To-DP" xfer stuff */
@@ -1641,5 +1667,5 @@ void tentoeth(register struct dpni20_s *
 #else
 	    cnt = write(pffd, buff, rcnt);
-#endif
+#endif	/* else KLH10_NET_DLPI */
 	    if (cnt != rcnt) {
 		if ((cnt < 0) && (errno == EINTR)) {
@@ -1702,4 +1728,7 @@ void dumppkt(unsigned char *ucp, int cnt
     }
 }
+
+
+
 
 /* Add OSDNET shared code here */
