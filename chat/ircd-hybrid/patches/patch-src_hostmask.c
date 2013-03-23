$NetBSD: patch-src_hostmask.c,v 1.1 2013/03/23 19:29:51 spz Exp $

fix http://secunia.com/advisories/51948/ (taken from
http://svn.ircd-hybrid.org:8000/viewcvs.cgi/ircd-hybrid/trunk/src/hostmask.c?r1=1786&r2=1785&pathrev=1786)

--- src/hostmask.c.orig	2007-02-28 04:17:46.000000000 +0000
+++ src/hostmask.c
@@ -198,7 +198,7 @@ try_parse_v4_netmask(const char *text, s
     {
       char *after;
       bits = strtoul(p + 1, &after, 10);
-      if (!bits || *after)
+      if (bits < 0 || *after)
         return HM_HOST;
       if (bits > n * 8)
         return HM_HOST;
