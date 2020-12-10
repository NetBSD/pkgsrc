$NetBSD: patch-zebra_ioctl.c,v 1.1 2020/12/10 17:08:17 kardel Exp $

	use SIOCGIFDATA on NetBSD to fetch link status
	instead of relying on SIOCGIFMEDIA

--- zebra/ioctl.c.orig	2018-02-19 21:24:55.000000000 +0000
+++ zebra/ioctl.c
@@ -348,9 +348,6 @@ if_get_flags (struct interface *ifp)
 {
   int ret;
   struct ifreq ifreq;
-#ifdef HAVE_BSD_LINK_DETECT
-  struct ifmediareq ifmr;
-#endif /* HAVE_BSD_LINK_DETECT */
 
   ifreq_set_name (&ifreq, ifp);
 
@@ -360,33 +357,74 @@ if_get_flags (struct interface *ifp)
       zlog_err("if_ioctl(SIOCGIFFLAGS) failed: %s", safe_strerror(errno));
       return;
     }
-#ifdef HAVE_BSD_LINK_DETECT /* Detect BSD link-state at start-up */
 
-  /* Per-default, IFF_RUNNING is held high, unless link-detect says
-   * otherwise - we abuse IFF_RUNNING inside zebra as a link-state flag,
-   * following practice on Linux and Solaris kernels
-   */
-  SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
-  
-  if (CHECK_FLAG (ifp->status, ZEBRA_INTERFACE_LINKDETECTION))
-    {
-      (void) memset(&ifmr, 0, sizeof(ifmr));
-      strncpy (ifmr.ifm_name, ifp->name, IFNAMSIZ);
-      
-      /* Seems not all interfaces implement this ioctl */
-      if (if_ioctl(SIOCGIFMEDIA, (caddr_t) &ifmr) < 0)
-        zlog_err("if_ioctl(SIOCGIFMEDIA) failed: %s", safe_strerror(errno));
-      else if (ifmr.ifm_status & IFM_AVALID) /* Link state is valid */
-        {
-          if (ifmr.ifm_status & IFM_ACTIVE)
-            SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
-          else
-            UNSET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+    if (!CHECK_FLAG(ifp->status, ZEBRA_INTERFACE_LINKDETECTION))
+	goto out;
+
+#ifdef SIOCGIFDATA
+	/*
+	 * BSD gets link state from ifi_link_link in struct if_data.
+	 * All BSD's have this in getifaddrs(3) ifa_data for AF_LINK addresses.
+	 * We can also access it via SIOCGIFDATA.
+	 */
+
+#ifdef __NetBSD__
+	struct ifdatareq ifdr = { .ifdr_data.ifi_link_state = 0 };
+	struct if_data *ifdata = &ifdr.ifdr_data;
+
+	strlcpy(ifdr.ifdr_name, ifp->name, sizeof(ifdr.ifdr_name));
+	ret = if_ioctl(SIOCGIFDATA, (caddr_t)&ifdr);
+#else
+	struct if_data ifd = { .ifi_link_state = 0 };
+	struct if_data *ifdata = &ifd;
+
+	ifreq.ifr_data = (caddr_t)ifdata;
+	ret = if_ioctl(SIOCGIFDATA, (caddr_t)&ifreq);
+#endif
+
+	if (ret == -1)
+		/* Very unlikely. Did the interface disappear? */
+		zlog_err("if_ioctl(SIOCGIFDATA) failed: %s",
+			     safe_strerror(errno));
+	else {
+		if (ifdata->ifi_link_state >= LINK_STATE_UP)
+			SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+		else if (ifdata->ifi_link_state == LINK_STATE_UNKNOWN)
+			/* BSD traditionally treats UNKNOWN as UP */
+			SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+		else
+			UNSET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+	}
+
+#elif defined(HAVE_BSD_LINK_DETECT)
+	/*
+	 * This is only needed for FreeBSD older than FreeBSD-13.
+	 * Valid and active media generally means the link state is
+	 * up, but this is not always the case.
+	 * For example, some BSD's with a net80211 interface in MONITOR
+	 * mode will treat the media as valid and active but the
+	 * link state is down - because we cannot send anything.
+	 * Also, virtual interfaces such as PPP, VLAN, etc generally
+	 * don't support media at all, so the ioctl will just fail.
+	 */
+	struct ifmediareq ifmr = { .ifm_status = 0 };
+
+	strlcpy(ifmr.ifm_name, ifp->name, sizeof(ifmr.ifm_name));
+
+	if (if_ioctl(SIOCGIFMEDIA, (caddr_t)&ifmr) == -1) {
+		if (errno != EINVAL)
+		      zlog_err("if_ioctl(SIOCGIFMEDIA) failed: %s",
+				   safe_strerror(errno));
+	} else if (ifmr.ifm_status & IFM_AVALID) { /* media state is valid */
+		if (ifmr.ifm_status & IFM_ACTIVE) /* media is active */
+			SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+		else
+			UNSET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
         }
-  }
 #endif /* HAVE_BSD_LINK_DETECT */
 
-  if_flags_update (ifp, (ifreq.ifr_flags & 0x0000ffff));
+out:
+    if_flags_update (ifp, (ifreq.ifr_flags & 0x0000ffff));
 }
 
 /* Set interface flags */
