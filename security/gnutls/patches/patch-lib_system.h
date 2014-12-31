$NetBSD: patch-lib_system.h,v 1.1 2014/12/31 16:05:07 rumko Exp $

At least on FreeBSD, arpa/inet.h does not contain IPV6
related structs.

See https://savannah.gnu.org/support/?108713

--- lib/system.h.orig	2014-12-30 11:12:37.607361021 +0000
+++ lib/system.h
@@ -98,7 +98,12 @@ int _gnutls_ucs2_to_utf8(const void *dat
 int gnutls_system_global_init(void);
 void gnutls_system_global_deinit(void);
 
+#if defined(HAVE_NETINET_IN_H)
+#include <netinet/in.h>
+#else
 #include <arpa/inet.h>
+#endif
+
 #ifdef _WIN32
 # define inet_aton _gnutls_inet_aton
 int inet_aton(const char *cp, struct in_addr *inp);
