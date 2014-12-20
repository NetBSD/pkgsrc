$NetBSD: patch-ntpd_ntp__io.c,v 1.1 2014/12/20 09:45:46 taca Exp $

Fix from NetBSD base.

--- ntpd/ntp_io.c.orig	2014-12-19 11:56:55.000000000 +0000
+++ ntpd/ntp_io.c
@@ -217,7 +217,7 @@ static	isc_boolean_t	socket_multicast_di
 #ifdef DEBUG
 static void interface_dump	(const endpt *);
 static void sockaddr_dump	(const sockaddr_u *);
-static void print_interface	(const endpt *, char *, char *);
+static void print_interface	(const endpt *, const char *, const char *);
 #define DPRINT_INTERFACE(level, args) do { if (debug >= (level)) { print_interface args; } } while (0)
 #else
 #define DPRINT_INTERFACE(level, args) do {} while (0)
@@ -550,7 +550,7 @@ sockaddr_dump(const sockaddr_u *psau)
  * print_interface - helper to output debug information
  */
 static void
-print_interface(const endpt *iface, char *pfx, char *sfx)
+print_interface(const endpt *iface, const char *pfx, const char *sfx)
 {
 	printf("%sinterface #%d: fd=%d, bfd=%d, name=%s, flags=0x%x, ifindex=%u, sin=%s",
 	       pfx,
@@ -1647,16 +1647,15 @@ set_wildcard_reuse(
 
 
 static isc_boolean_t
-is_anycast(
+check_flags6(
 	sockaddr_u *psau,
-	const char *name
+	const char *name,
+	u_int32 flags6
 	)
 {
-#if defined(INCLUDE_IPV6_SUPPORT) && defined(SIOCGIFAFLAG_IN6) && \
-    defined(IN6_IFF_ANYCAST)
+#if defined(INCLUDE_IPV6_SUPPORT) && defined(SIOCGIFAFLAG_IN6)
 	struct in6_ifreq ifr6;
 	int fd;
-	u_int32 flags6;
 
 	if (psau->sa.sa_family != AF_INET6)
 		return ISC_FALSE;
@@ -1670,13 +1669,45 @@ is_anycast(
 		return ISC_FALSE;
 	}
 	close(fd);
-	flags6 = ifr6.ifr_ifru.ifru_flags6;
-	if ((flags6 & IN6_IFF_ANYCAST) != 0)
+	if ((ifr6.ifr_ifru.ifru_flags6 & flags6) != 0)
 		return ISC_TRUE;
-#endif	/* INCLUDE_IPV6_SUPPORT && SIOCGIFAFLAG_IN6 && IN6_IFF_ANYCAST */
+#endif	/* INCLUDE_IPV6_SUPPORT && SIOCGIFAFLAG_IN6 */
 	return ISC_FALSE;
 }
 
+static isc_boolean_t
+is_anycast(
+	sockaddr_u *psau,
+	const char *name
+	)
+{
+#ifdef IN6_IFF_ANYCAST
+	return check_flags6(psau, name, IN6_IFF_ANYCAST);
+#else
+	return ISC_FALSE;
+#endif
+}
+
+static isc_boolean_t
+is_valid(
+	sockaddr_u *psau,
+	const char *name
+	)
+{
+	u_int32 flags6;
+
+	flags6 = 0;
+#ifdef IN6_IFF_DEPARTED
+	flags6 |= IN6_IFF_DEPARTED;
+#endif
+#ifdef IN6_IFF_DETACHED
+	flags6 |= IN6_IFF_DETACHED;
+#endif
+#ifdef IN6_IFF_TENTATIVE
+	flags6 |= IN6_IFF_TENTATIVE;
+#endif
+	return check_flags6(psau, name, flags6) ? ISC_FALSE : ISC_TRUE;
+}
 
 /*
  * update_interface strategy
@@ -1810,6 +1841,12 @@ update_interfaces(
 			continue;
 
 		/*
+		 * skip any address that is an invalid state to be used
+		 */
+		if (!is_valid(&enumep.sin, isc_if.name))
+			continue;
+
+		/*
 		 * map to local *address* in order to map all duplicate
 		 * interfaces to an endpt structure with the appropriate
 		 * socket.  Our name space is (ip-address), NOT
@@ -1969,6 +2006,9 @@ update_interfaces(
 	if (broadcast_client_enabled)
 		io_setbclient();
 
+	if (sys_bclient)
+		io_setbclient();
+
 	return new_interface_found;
 }
 
@@ -2795,7 +2835,6 @@ open_socket(
 {
 	SOCKET	fd;
 	int	errval;
-	char	scopetext[16];
 	/*
 	 * int is OK for REUSEADR per
 	 * http://www.kohala.com/start/mcast.api.txt
@@ -2945,16 +2984,10 @@ open_socket(
 		    || debug > 1
 #endif
 		    ) {
-			if (SCOPE(addr))
-				snprintf(scopetext, sizeof(scopetext),
-					 "%%%d", SCOPE(addr));
-			else
-				scopetext[0] = 0;
-
 			msyslog(LOG_ERR,
-				"bind(%d) AF_INET%s %s%s#%d%s flags 0x%x failed: %m",
+				"bind(%d) AF_INET%s %s#%d%s flags 0x%x failed: %m",
 				fd, IS_IPV6(addr) ? "6" : "",
-				stoa(addr), scopetext, SRCPORT(addr),
+				stoa(addr), SRCPORT(addr),
 				IS_MCAST(addr) ? " (multicast)" : "",
 				interf->flags);
 		}
@@ -3198,8 +3231,8 @@ read_refclock_packet(
 	}
 
 	i = (rp->datalen == 0
-	     || rp->datalen > sizeof(rb->recv_space))
-		? sizeof(rb->recv_space)
+	     || rp->datalen > (int)sizeof(rb->recv_space))
+		? (int)sizeof(rb->recv_space)
 		: rp->datalen;
 	do {
 		buflen = read(fd, (char *)&rb->recv_space, (u_int)i);
@@ -3321,8 +3354,8 @@ fetch_timestamp(
 					tvp->tv_usec = (long)(ticks * 1e6 *
 							      sys_tick);
 				}
-				DPRINTF(4, ("fetch_timestamp: system usec network time stamp: %ld.%06ld\n",
-					    tvp->tv_sec, tvp->tv_usec));
+				DPRINTF(4, ("fetch_timestamp: system usec network time stamp: %jd.%06ld\n",
+					    (intmax_t)tvp->tv_sec, (long)tvp->tv_usec));
 				nts = tval_stamp_to_lfp(*tvp);
 				break;
 #endif  /* HAVE_TIMESTAMP */
@@ -3454,15 +3487,15 @@ read_network_packet(
 	if (AF_INET6 == itf->family) {
 		DPRINTF(1, ("Got an IPv6 packet, from <%s> (%d) to <%s> (%d)\n",
 			stoa(&rb->recv_srcadr),
-			IN6_IS_ADDR_LOOPBACK(&rb->recv_srcadr),
+			IN6_IS_ADDR_LOOPBACK(&SOCK_ADDR6(&rb->recv_srcadr)),
 			stoa(&itf->sin),
-			!IN6_IS_ADDR_LOOPBACK(&itf->sin)
+			!IN6_IS_ADDR_LOOPBACK(&SOCK_ADDR6(&itf->sin))
 			));
 	}
 
 	if (   AF_INET6 == itf->family
-	    && IN6_IS_ADDR_LOOPBACK(&rb->recv_srcadr)
-	    && !IN6_IS_ADDR_LOOPBACK(&itf->sin)
+	    && IN6_IS_ADDR_LOOPBACK(&SOCK_ADDR6(&rb->recv_srcadr))
+	    && !IN6_IS_ADDR_LOOPBACK(&SOCK_ADDR6(&itf->sin))
 	   ) {
 		packets_dropped++;
 		DPRINTF(1, ("DROPPING that packet\n"));
@@ -4040,7 +4073,7 @@ calc_addr_distance(
 
 	found_greater = FALSE;
 	a1_greater = FALSE;	/* suppress pot. uninit. warning */
-	for (i = 0; i < sizeof(NSRCADR6(a1)); i++) {
+	for (i = 0; i < (int)sizeof(NSRCADR6(a1)); i++) {
 		if (!found_greater &&
 		    NSRCADR6(a1)[i] != NSRCADR6(a2)[i]) {
 			found_greater = TRUE;
@@ -4083,7 +4116,7 @@ cmp_addr_distance(
 			return 1;
 	}
 
-	for (i = 0; i < sizeof(NSRCADR6(d1)); i++) {
+	for (i = 0; i < (int)sizeof(NSRCADR6(d1)); i++) {
 		if (NSRCADR6(d1)[i] < NSRCADR6(d2)[i])
 			return -1;
 		else if (NSRCADR6(d1)[i] > NSRCADR6(d2)[i])
