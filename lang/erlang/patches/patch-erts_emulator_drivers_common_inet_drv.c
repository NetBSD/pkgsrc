$NetBSD: patch-erts_emulator_drivers_common_inet_drv.c,v 1.1 2011/12/14 11:08:50 hans Exp $

Don't use SIOCGIFHWADDR on SunOS, there is no ifr_hwaddr.

--- erts/emulator/drivers/common/inet_drv.c.orig	2011-05-24 13:16:43.000000000 +0200
+++ erts/emulator/drivers/common/inet_drv.c	2011-12-14 11:35:59.168220052 +0100
@@ -4164,7 +4164,7 @@ static int inet_ctl_ifget(inet_descripto
 	    break;
 
 	case INET_IFOPT_HWADDR: {
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 	    if (ioctl(desc->s, SIOCGIFHWADDR, (char *)&ifreq) < 0)
 		break;
 	    buf_check(sptr, s_end, 1+2+IFHWADDRLEN);
