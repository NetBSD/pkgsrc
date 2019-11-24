$NetBSD: patch-lib_misc.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8084/
Add guards around GCC diagnostics pragma to allow for building on older vers

--- lib/misc.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ lib/misc.c
@@ -465,10 +465,6 @@ char *u32toIP(unsigned int ip32)
 	ip3 = ((ip32 >> 8) & 0xFF);
 	ip4 = (ip32 & 0xFF);
 
-	#pragma GCC diagnostic push
-	#pragma GCC diagnostic ignored "-Wformat-truncation"
-	#pragma GCC diagnostic pop
-
 	snprintf(result, result_buflen, "%d.%d.%d.%d", ip1, ip2, ip3, ip4);
 	return result;
 }
