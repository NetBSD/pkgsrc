$NetBSD: patch-zebra_ioctl.c,v 1.1 2020/12/10 16:43:24 kardel Exp $

	In NetBSD the correct way to determine link status is
	ifi_link_state in if_data. This also avoids many
	error messages on interfaces that do not support
	SIOCGIFMEDIA.

--- zebra/ioctl.c.orig	2020-06-30 11:08:57.000000000 +0000
+++ zebra/ioctl.c
@@ -421,9 +421,6 @@ void if_get_flags(struct interface *ifp)
 {
 	int ret;
 	struct ifreq ifreq;
-#ifdef HAVE_BSD_LINK_DETECT
-	struct ifmediareq ifmr;
-#endif /* HAVE_BSD_LINK_DETECT */
 
 	ifreq_set_name(&ifreq, ifp);
 
@@ -434,34 +431,80 @@ void if_get_flags(struct interface *ifp)
 			     safe_strerror(errno));
 		return;
 	}
-#ifdef HAVE_BSD_LINK_DETECT /* Detect BSD link-state at start-up */
+
+	if (!CHECK_FLAG(ifp->status, ZEBRA_INTERFACE_LINKDETECTION))
+		goto out;
 
 	/* Per-default, IFF_RUNNING is held high, unless link-detect says
 	 * otherwise - we abuse IFF_RUNNING inside zebra as a link-state flag,
 	 * following practice on Linux and Solaris kernels
 	 */
-	SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
 
-	if (CHECK_FLAG(ifp->status, ZEBRA_INTERFACE_LINKDETECTION)) {
-		(void)memset(&ifmr, 0, sizeof(ifmr));
-		strlcpy(ifmr.ifm_name, ifp->name, sizeof(ifmr.ifm_name));
-
-		/* Seems not all interfaces implement this ioctl */
-		if (if_ioctl(SIOCGIFMEDIA, (caddr_t)&ifmr) == -1 &&
-		    errno != EINVAL)
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
+	ret = vrf_if_ioctl(SIOCGIFDATA, (caddr_t)&ifdr, ifp->vrf_id);
+#else
+	struct if_data ifd = { .ifi_link_state = 0 };
+	struct if_data *ifdata = &ifd;
+
+	ifreq.ifr_data = (caddr_t)ifdata;
+	ret = vrf_if_ioctl(SIOCGIFDATA, (caddr_t)&ifreq, ifp->vrf_id);
+#endif
+
+	if (ret == -1)
+		/* Very unlikely. Did the interface disappear? */
+		flog_err_sys(EC_LIB_SYSTEM_CALL,
+			     "if_ioctl(SIOCGIFDATA) failed: %s",
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
 			flog_err_sys(EC_LIB_SYSTEM_CALL,
 				     "if_ioctl(SIOCGIFMEDIA) failed: %s",
 				     safe_strerror(errno));
-		else if (ifmr.ifm_status & IFM_AVALID) /* Link state is valid */
-		{
-			if (ifmr.ifm_status & IFM_ACTIVE)
-				SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
-			else
-				UNSET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
-		}
+	} else if (ifmr.ifm_status & IFM_AVALID) { /* media state is valid */
+		if (ifmr.ifm_status & IFM_ACTIVE) /* media is active */
+			SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+		else
+			UNSET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
 	}
 #endif /* HAVE_BSD_LINK_DETECT */
 
+out:
 	if_flags_update(ifp, (ifreq.ifr_flags & 0x0000ffff));
 }
 
