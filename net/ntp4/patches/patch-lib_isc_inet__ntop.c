$NetBSD: patch-lib_isc_inet__ntop.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- lib/isc/inet_ntop.c.orig	2015-02-28 09:44:07.000000000 +0000
+++ lib/isc/inet_ntop.c
@@ -88,11 +88,11 @@ isc_net_ntop(int af, const void *src, ch
 static const char *
 inet_ntop4(const unsigned char *src, char *dst, size_t size)
 {
-	static const char *fmt = "%u.%u.%u.%u";
+#define	FMT "%u.%u.%u.%u"
 	char tmp[sizeof("255.255.255.255")];
 	int len;
 
-	len = snprintf(tmp, sizeof(tmp), fmt, src[0], src[1], src[2], src[3]);
+	len = snprintf(tmp, sizeof(tmp), FMT, src[0], src[1], src[2], src[3]);
 	if (len < 0 || (size_t)len >= size)
 	{
 		errno = ENOSPC;
