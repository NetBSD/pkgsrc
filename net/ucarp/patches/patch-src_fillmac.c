$NetBSD: patch-src_fillmac.c,v 1.2 2013/12/10 17:56:23 jperkin Exp $

Add SIOCGLIFHWADDR support on newer SunOS.

--- src/fillmac.c.orig	2007-07-04 13:34:59.000000000 +0000
+++ src/fillmac.c
@@ -43,7 +43,22 @@ int fill_mac_address(void)
                 strerror(errno));
         return -1;
     }
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGLIFHWADDR) && defined(__sun)
+    {
+	struct lifreq lifr;
+	struct sockaddr_dl *sdl;
+	strncpy(lifr.lifr_name, interface, sizeof lifr.lifr_name);
+	if (ioctl(s, SIOCGLIFHWADDR, &lifr) != 0) {
+		logfile(LOG_ERR,
+		     _("Unable to get hardware info about an interface: %s"),
+		    strerror(errno));
+		(void) close(s);
+		return -1;
+	}
+	sdl = (struct sockaddr_dl *)&lifr.lifr_addr;
+	memcpy(hwaddr, LLADDR(sdl), sdl->sdl_alen);
+    }
+#elif defined(SIOCGIFHWADDR)
     {
         struct ifreq ifr;
         
