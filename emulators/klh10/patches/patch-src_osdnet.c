$NetBSD: patch-src_osdnet.c,v 1.1 2013/10/17 15:41:10 ryoon Exp $

http://www.falu.nl/~rhialto/klh-diffs2

--- src/osdnet.c.orig	2005-04-28 22:01:04.000000000 +0000
+++ src/osdnet.c
@@ -68,7 +68,7 @@ int
 osn_ifsock(char *ifnam, ossock_t *as)
 {
 #if (KLH10_NET_NIT || KLH10_NET_DLPI || KLH10_NET_BPF || KLH10_NET_PFLT || \
-	KLH10_NET_TUN || KLH10_NET_LNX)
+	KLH10_NET_TUN || KLH10_NET_LNX || KLH10_NET_TAP_BRIDGE)
     return ((*as = socket(AF_INET, SOCK_DGRAM, 0)) >= 0);
 #else
 # error OSD implementation needed for osn_ifsock
@@ -79,7 +79,7 @@ int
 osn_ifclose(ossock_t s)
 {
 #if (KLH10_NET_NIT || KLH10_NET_DLPI || KLH10_NET_BPF || KLH10_NET_PFLT || \
-	KLH10_NET_TUN || KLH10_NET_LNX)
+	KLH10_NET_TUN || KLH10_NET_LNX || KLH10_NET_TAP_BRIDGE)
     return (close(s) >= 0);
 #else
 # error OSD implementation needed for osn_ifclose
@@ -161,6 +161,12 @@ or alternatively:
 	? (sizeof(struct ifreq) - sizeof(struct sockaddr) + (ifr).ifr_addr.sa_len) \
 	: sizeof(struct ifreq))
 
+  This has been made trickier by NetBSD 5.0, which doesn't put a sockaddr
+  but a (union with as largest member a) sockaddr_storage in the ifreq.
+  Now the size is always the same again, but not sizeof(struct sockaddr).
+  This can (probably) be recognised by the existence of
+  #define	ifr_space	ifr_ifru.ifru_space   / * sockaddr_storage * /
+
 */
 /*
   Note that searching for AF_INET or IP addresses only finds interfaces that
@@ -288,7 +294,7 @@ osn_iftab_pass(int opts, int npass, int 
 	   uses a variable-size "ifreq" entry!  Choke...
 	 */
 	ifnext = ifp + 1;	/* Assume normal entry at first */
-#if NETIF_HAS_SALEN
+#if NETIF_HAS_SALEN && !defined(ifr_space)
 	if (ifp->ifr_addr.sa_len > sizeof(struct sockaddr)) {
 	    offset = ifp->ifr_addr.sa_len - sizeof(struct sockaddr);
 	    ifnext = (struct ifreq *)((char *)ifnext + offset);
@@ -382,6 +388,8 @@ osn_iftab_pass(int opts, int npass, int 
     }
 }
 
+#include <stddef.h>
+
 void
 osn_ifctab_show(FILE *f, struct ifconf *ifc)
 {
@@ -393,7 +401,14 @@ osn_ifctab_show(FILE *f, struct ifconf *
     int nents = 0;
     int nvary = 0;
 
-    fprintf(f, "Interface table: %ld bytes (%d entries if std addr len %d)\n",
+    fprintf(f, "sizeof struct ifreq = %d\r\n", (int) sizeof(struct ifreq));
+    fprintf(f, "IFNAMSIZ = %d\r\n", (int) IFNAMSIZ);
+    fprintf(f, "offset of struct sockaddr_storage = %d\r\n", (int) offsetof(struct ifreq, ifr_space));
+    fprintf(f, "sizeof struct sockaddr = %d\r\n", (int) sizeof(struct sockaddr));
+    fprintf(f, "sizeof struct sockaddr_storage = %d\r\n", (int) sizeof(struct sockaddr_storage));
+    fprintf(f, "sizeof union ifr_ifru = %d\r\n", (int) sizeof(ifr->ifr_ifru));
+
+    fprintf(f, "Interface table: %ld bytes (%d entries if std addr len %d)\r\n",
 	    (long)ifc->ifc_len, ifc->ifc_len/sizeof(struct ifreq),
 	    (int)sizeof(struct sockaddr));
 
@@ -408,18 +423,19 @@ osn_ifctab_show(FILE *f, struct ifconf *
 	len = sizeof(struct sockaddr);
 #endif
 
+	fprintf(f, "offset: %d\r\n", (int)((char *)ifr - (char *)ifc->ifc_req));
 	/* Output entry data */
-	fprintf(f, "%2d: \"%.*s\" fam %d, len %d",
+	fprintf(f, "%2d: \"%.*s\" sockaddr.sa_family %d, .sa_len %d",
 		i, (int)sizeof(ifr->ifr_name), ifr->ifr_name,
 		ifr->ifr_addr.sa_family, len);
 	if (len) {
 	    cp = (unsigned char *) ifr->ifr_addr.sa_data;
-	    fprintf(f, " = %x", *cp);
+	    fprintf(f, " = (sockaddr.sa_data) %x", *cp);
 	    for (--len; len > 0; --len) {
 		fprintf(f, ":%x", *++cp);
 	    }
 	}
-	fprintf(f, "\n");
+	fprintf(f, "\r\n");
 
 	cp = (unsigned char *) ifr->ifr_addr.sa_data;
 	switch (ifr->ifr_addr.sa_family) {
@@ -429,7 +445,7 @@ osn_ifctab_show(FILE *f, struct ifconf *
 	    struct in_addr *in = &skin->sin_addr;
 	    unsigned char *ucp = (unsigned char *) &in->s_addr;
 
-	    fprintf(f, "        AF_INET = port %d, IP %d.%d.%d.%d\n",
+	    fprintf(f, "        AF_INET = port %d, IP %d.%d.%d.%d\r\n",
 		    (int)skin->sin_port,
 		    ucp[0], ucp[1], ucp[2], ucp[3]);
 	  }
@@ -439,7 +455,7 @@ osn_ifctab_show(FILE *f, struct ifconf *
 	case AF_LINK:
 	  {
 	    struct sockaddr_dl *dla = (struct sockaddr_dl *) &ifr->ifr_addr;
-	    fprintf(f, "        AF_LINK = type %d, alen %d",
+	    fprintf(f, "        AF_LINK = type %d, sdl_alen %d",
 		    dla->sdl_type, dla->sdl_alen);
 	    if (len = dla->sdl_alen) {
 		cp = (unsigned char *) LLADDR(dla);
@@ -448,18 +464,23 @@ osn_ifctab_show(FILE *f, struct ifconf *
 		    fprintf(f, ":%x", *++cp);
 		}
 	    }
-	    fprintf(f, "\n");
+	    fprintf(f, "\r\n");
 	  }
 	    break;
 #endif
 
+#if defined(AF_INET6)
+	case AF_INET6:
+	    fprintf(f, "        AF_INET6 (No handler for this)\r\n");
+	    break;
+#endif
 	default:
-	    fprintf(f, "        No handler for this family\n");
+	    fprintf(f, "        No handler for this family\r\n");
 	}
 
 
 	/* Move onto next entry */
-#if NETIF_HAS_SALEN
+#if NETIF_HAS_SALEN && !defined(ifr_space)
 	if (ifr->ifr_addr.sa_len > sizeof(struct sockaddr)) {
 	    ++nvary;
 	    ifr = (struct ifreq *)((char *)(ifr + 1) +
@@ -469,10 +490,10 @@ osn_ifctab_show(FILE *f, struct ifconf *
 	ifr++;
     }
     if (nvary)
-	fprintf(f, "Interface summary: %d entries of varying length\n",
+	fprintf(f, "Interface summary: %d entries of varying length\r\n",
 		nents);
     else
-	fprintf(f, "Interface summary: %d entries of std length %d\n",
+	fprintf(f, "Interface summary: %d entries of std length %d\r\n",
 		nents, (int)sizeof(struct ifreq));
 }
 
@@ -483,7 +504,7 @@ osn_iftab_show(FILE *f, struct ifent *if
     register struct ifent *ife;
     int i;
 
-    fprintf(f, "Filtered IFE table: %d entries\n", nents);
+    fprintf(f, "Filtered IFE table: %d entries\r\n", nents);
 
     for (i = 0, ife = ifents; i < nents; ++i, ++ife) {
 	fprintf(f, "%2d: \"%s\"", i, ife->ife_name);
@@ -502,7 +523,7 @@ osn_iftab_show(FILE *f, struct ifent *if
 	    fprintf(f, " (Other: fam %d)",
 		    ife->ife_pother->ifr_addr.sa_family);
 	}
-	fprintf(f, "\n");
+	fprintf(f, "\r\n");
     }
 }
 
@@ -897,6 +918,9 @@ osn_ifeaget(int s,		/* Socket for (AF_IN
     return TRUE;
 }
 
+static struct eth_addr emhost_ea = 	/* Emulated host ether addr for tap */
+    { 0xf2, 0x0b, 0xa4, 0xff, 0xff, 0xff };
+
 /* OSN_PFEAGET - get physical ethernet address for an open packetfilter FD.
  *
  * Also not well documented, but generally easier to perform.
@@ -945,8 +969,20 @@ osn_pfeaget(int pfs,		/* Packetfilter so
     }
     ea_set(eap, endp.end_addr);
 
-#elif KLH10_NET_BPF && !CENV_SYS_NETBSD && !CENV_SYS_FREEBSD
-    /* NetBSD no longer seems to support this */
+#elif KLH10_NET_TAP_BRIDGE
+    /* If we do tap(4) + bridge(4), the ether address of the tap is wholly
+     * irrelevant, it is on the other side of the "wire".
+     * Our own address is something we can make up completely.
+     */
+    if (emhost_ea.ea_octets[5] == 0xFF) {
+	time_t t = time(NULL);
+	emhost_ea.ea_octets[5] =  t        & 0xFE;
+	emhost_ea.ea_octets[4] = (t >>  8) & 0xFF;
+	emhost_ea.ea_octets[3] = (t >> 16) & 0xFF;
+    }
+    ea_set(eap, &emhost_ea);	/* Return the ether address */
+#elif (KLH10_NET_BPF && !CENV_SYS_NETBSD && !CENV_SYS_FREEBSD)
+    /* NetBSD no longer seems to support this (on bpf) */
     struct ifreq ifr;
 
     strncpy(ifr.ifr_name, ifnam, sizeof(ifr.ifr_name));
@@ -1131,7 +1167,7 @@ osn_ifeaset(int s,		/* Socket for (AF_IN
 	    char *ifnam,	/* Interface name */
 	    unsigned char *newpa)	/* New ether address */
 {
-#if CENV_SYS_DECOSF || KLH10_NET_LNX \
+#if CENV_SYS_DECOSF || KLH10_NET_LNX || KLH10_NET_TAP_BRIDGE \
 		    || (CENV_SYS_FREEBSD && defined(SIOCSIFLLADDR))
 
     /* Common preamble code */
@@ -1190,6 +1226,8 @@ osn_ifeaset(int s,		/* Socket for (AF_IN
 	if (ownsock) close(s);
 	return FALSE;
     }
+# elif KLH10_NET_TAP_BRIDGE
+    ea_set(&emhost_ea, newpa);
 # else
 #  error "Unimplemented OS routine osn_ifeaset()"
 # endif
@@ -1338,6 +1376,7 @@ pfopen(void)
 }
 
 #endif /* KLH10_NET_PFLT || KLH10_NET_BPF */
+
 
 #if KLH10_NET_PFLT
 
@@ -1916,6 +1955,212 @@ osn_pfinit(struct osnpf *osnpf, void *ar
 }
 #endif /* KLH10_NET_NIT */
 
+/*
+ * Too bad that this is never called...
+ */
+osn_pfdeinit()
+{
+#if KLH10_NET_TAP_BRIDGE
+    void tap_bridge_close();
+    tap_bridge_close();
+#endif
+}
+
+#if KLH10_NET_TAP_BRIDGE
+
+osn_pfinit(register struct osnpf *osnpf, void *arg)
+{
+    int fd;
+    char *ifnam = osnpf->osnpf_ifnam;
+
+    /* No "default interface" concept here */
+    if (!ifnam || !ifnam[0])
+	esfatal(1, "Packetfilter interface must be specified");
+
+    fd = tap_bridge_open(ifnam);
+
+    /* Now get our fresh new virtual interface's ethernet address.
+    */
+    (void) osn_pfeaget(fd, ifnam, (unsigned char *)&(osnpf->osnpf_ea));
+
+    return fd;
+}
+
+#include <net/if_tap.h>
+#include <net/if_bridgevar.h>
+#include <stdint.h>
+
+static struct ifreq br_ifr;
+static struct ifreq tap_ifr;
+static int my_tap;
+
+/*
+ * A TAP is a virtual ethernet interface, much like TUN is a virtual IP
+ * interface. We can use it to inject packets into the Unix input stream,
+ * provided it is UP and the host side has a matching IP address and
+ * netmask (also much like TUN), or that it is bridged to another interface.
+ *
+ * Here we try to create the user-given interface and then bridge it to
+ * the "default" interface. This is probably the most common configuration.
+ * If something else is desired, the user can set up the tap herself,
+ * and we'll just use it as it is. This is useful for a routed approach,
+ * for instance.
+ */
+int
+tap_bridge_open(char *ifnam)
+{
+    int tapfd;
+    int res;
+    union ipaddr netmask;
+    char cmdbuff[128];
+    struct ifent *ife;
+    int s;
+    int i;
+    struct ifbreq br_req;
+    struct ifdrv br_ifd;
+
+    if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
+	esfatal(1, "tap_bridge_open: socket() failed");
+    }
+
+    /* try to create tapN as specified by the user */
+    memset(&tap_ifr, 0, sizeof(tap_ifr));
+    strcpy(tap_ifr.ifr_name, ifnam);
+    res = ioctl(s, SIOCIFCREATE, &tap_ifr);
+    if (res == 0) {
+	my_tap = 1;
+	dbprintln("Created host-side tap \"%s\"", ifnam);
+    } else {
+	if (errno != EEXIST)
+	    esfatal(1, "tap_bridge_open: can't create tap \"%s\"?", ifnam);
+	my_tap = 0;
+	dbprintln("Host-side tap \"%s\" alread exists; use it as-is", ifnam);
+    }
+
+    sprintf(cmdbuff, "/dev/%s", ifnam);
+    tapfd = open(cmdbuff, O_RDWR, 0);
+
+    if (tapfd < 0) {
+	/* Note possible error meanings:
+	   ENOENT - no such filename
+	   ENXIO  - not configured in kernel
+	*/
+	esfatal(1, "Couldn't find or open 10-side tap \"%s\"", cmdbuff);
+    }
+
+    dbprintln("Opened 10-side tap \"%s\"", cmdbuff);
+
+    /* Finally, turn on IFF_UP just in case the above didn't do it.
+       Note interface name is still there from the SIOCIFCREATE.
+     */
+    if (ioctl(s, SIOCGIFFLAGS, &tap_ifr) < 0) {
+	esfatal(1, "tap_bridge_open tap SIOCGIFFLAGS failed");
+    }
+    if (!(tap_ifr.ifr_flags & IFF_UP)) {
+	tap_ifr.ifr_flags |= IFF_UP;
+	if (ioctl(s, SIOCSIFFLAGS, &tap_ifr) < 0) {
+	    esfatal(1, "tap_bridge_open tap SIOCSIFFLAGS failed");
+	}
+	if (DP_DBGFLG)
+	    dbprint("tap_bridge_open tap did SIOCSIFFLAGS");
+    }
+
+    if (my_tap) {
+	for (i = 0; i < 1000; i++) {
+	    /* try to create bridge%d */
+	    memset(&br_ifr, 0, sizeof(br_ifr));
+	    sprintf(br_ifr.ifr_name, "bridge%d", i);
+	    res = ioctl(s, SIOCIFCREATE, &br_ifr);
+	    if (res == 0)
+		break;
+	    if (errno != EEXIST)
+		esfatal(1, "tap_bridge_open: can't create bridge \"%s\"?", br_ifr.ifr_name);
+	}
+	dbprintln("Created bridge \"%s\"", br_ifr.ifr_name);
+
+	/*
+	 * Find default IP interface to bridge with.
+	 * It might find the wrong one if there is more than one.
+	 */
+
+	ife = osn_ipdefault();
+	if (!ife)
+	    esfatal(0, "Couldn't find default interface");
+
+	if (swstatus)
+	    dbprintln("Bridging with default interface \"%s\"", ife->ife_name);
+
+	if (1) {
+	    sprintf(cmdbuff, "/sbin/brconfig %s add %s add %s up",
+		    br_ifr.ifr_name, ife->ife_name, ifnam);
+	    res = system(cmdbuff);
+	    dbprintln("%s => %d", cmdbuff, res);
+	} else {
+	    /* do whatever brconfig bridge0 add intf0 does... */
+	    memset(&br_ifd, 0, sizeof(br_ifd));
+	    memset(&br_req, 0, sizeof(br_req));
+
+	    /* set name of the bridge */
+	    strcpy(br_ifd.ifd_name, br_ifr.ifr_name);
+	    br_ifd.ifd_cmd = BRDGADD;
+	    br_ifd.ifd_len = sizeof(br_req);
+	    br_ifd.ifd_data = &br_req;
+
+	    /* brconfig bridge0 add tap0 (the virtual interface) */
+	    strcpy(br_req.ifbr_ifsname, ifnam);
+	    res = ioctl(s, SIOCSDRVSPEC, &br_ifd);
+	    if (res == -1)
+		esfatal(1, "tap_bridge_open: can't add virtual intf to bridge?");
+
+	    /* brconfig bridge0 add vr0 (the hardware interface) */
+	    strcpy(br_req.ifbr_ifsname, ife->ife_name);
+	    res = ioctl(s, SIOCSDRVSPEC, &br_ifd);
+	    if (res == -1)
+		esfatal(1, "tap_bridge_open: can't add real intf to bridge?");
+
+	    /* Finally, turn on IFF_UP just in case the above didn't do it.
+	     * Note interface name is still there.
+	     */
+	    if (ioctl(s, SIOCGIFFLAGS, &br_ifr) < 0) {
+		esfatal(1, "tap_bridge_open bridge SIOCGIFFLAGS failed");
+	    }
+	    if (!(br_ifr.ifr_flags & IFF_UP)) {
+		br_ifr.ifr_flags |= IFF_UP;
+		if (ioctl(s, SIOCSIFFLAGS, &br_ifr) < 0) {
+		    esfatal(1, "tap_bridge_open bridge SIOCSIFFLAGS failed");
+		}
+		if (DP_DBGFLG)
+		    dbprint("tap_bridge_open bridge did SIOCSIFFLAGS");
+	    }
+
+	}
+    }
+    close(s);
+
+    return tapfd;		/* Success! */
+}
+
+void
+tap_bridge_close()
+{
+    if (my_tap) {
+	int s, res;
+	struct ifreq tap_ifr;
+
+	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
+	    esfatal(1, "tap_bridge_close: socket() failed");
+	}
+
+	/* Destroy bridge */
+	res = ioctl(s, SIOCIFDESTROY, &br_ifr);
+	res = ioctl(s, SIOCIFDESTROY, &tap_ifr);
+
+	close(s);
+    }
+}
+
+#endif /* KLH10_NET_TAP_BRIDGE */
+
 #if KLH10_NET_DLPI
 
 /* DLPI packetfilter initialization */
