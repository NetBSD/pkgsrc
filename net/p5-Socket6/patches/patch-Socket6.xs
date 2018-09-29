$NetBSD: patch-Socket6.xs,v 1.2 2018/09/29 18:09:10 sevan Exp $

Starting (between 8.99.22 and 8.99.25), path changed on ipsec.h
| Date:   Thu Sep 6 19:07:13 2018 +0000
|    Remove netinet6/ipsec.h.

Socket6.xs:68:30: fatal error: netinet6/ipsec.h: No such file or directory
 #  include <netinet6/ipsec.h>

DragonFly removed the IPsec stack it inherited

--- Socket6.xs.orig	2016-04-11 03:27:34.000000000 +0000
+++ Socket6.xs
@@ -62,9 +62,9 @@ const struct in6_addr in6addr_loopback =
 #ifdef __KAME__
 # include <sys/param.h>
 # include <net/route.h>
-# if defined(__FreeBSD__) && __FreeBSD_version >= 700048
+# if (defined(__FreeBSD__) && __FreeBSD_version >= 700048 )|| (defined(__NetBSD__) && __NetBSD_Version__ >= 899002500 )
 #  include <netipsec/ipsec.h>
-# elif !defined(__OpenBSD__)
+# elif !defined(__OpenBSD__) && !defined(__DragonFly__)
 #  include <netinet6/ipsec.h>
 # endif
 #endif
