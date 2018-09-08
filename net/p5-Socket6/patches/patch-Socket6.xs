$NetBSD: patch-Socket6.xs,v 1.1 2018/09/08 23:35:09 mef Exp $

Starting (between 8.99.22 and 8.99.25), path changed on ipsec.h
| Date:   Thu Sep 6 19:07:13 2018 +0000
|    Remove netinet6/ipsec.h.

Socket6.xs:68:30: fatal error: netinet6/ipsec.h: No such file or directory
 #  include <netinet6/ipsec.h>

--- Socket6.c.orig	2018-09-09 07:59:51.799287247 +0900
+++ Socket6.xs	2018-09-09 08:01:38.735684757 +0900
@@ -71,7 +71,7 @@ const struct in6_addr in6addr_loopback =
 #ifdef __KAME__
 # include <sys/param.h>
 # include <net/route.h>
-# if defined(__FreeBSD__) && __FreeBSD_version >= 700048
+# if (defined(__FreeBSD__) && __FreeBSD_version >= 700048 )|| (defined(__NetBSD__) && __NetBSD_Version__ >= 899002500 )
 #  include <netipsec/ipsec.h>
 # elif !defined(__OpenBSD__)
 #  include <netinet6/ipsec.h>
