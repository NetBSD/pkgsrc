$NetBSD: patch-main.c,v 1.1 2019/12/30 22:17:29 rhialto Exp $

Our libnet11 package does not have the libnet_version() function,
apparently similar to OpenBSD.

--- main.c.orig	2019-08-30 11:09:00.000000000 +0000
+++ main.c
@@ -119,7 +119,7 @@ main_version(void)
 	fprintf(stderr, "rtlinked against libevent %s\n", event_get_version());
 #ifndef WITHOUT_MIRROR
 	fprintf(stderr, "compiled against libnet %s\n", LIBNET_VERSION);
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 	const char *lnv = libnet_version();
 	if (!strncmp(lnv, "libnet version ", 15))
 		lnv += 15;
