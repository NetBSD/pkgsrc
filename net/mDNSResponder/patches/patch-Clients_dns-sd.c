$NetBSD: patch-Clients_dns-sd.c,v 1.4 2011/10/04 14:08:48 hans Exp $

--- Clients/dns-sd.c.orig	2010-05-15 00:16:11.000000000 +0000
+++ Clients/dns-sd.c
@@ -170,8 +170,19 @@ cl dns-sd.c -I../mDNSShared -DNOT_HAVE_G
 	#include <arpa/inet.h>		// For inet_addr()
 	#include <net/if.h>			// For if_nametoindex()
 	static const char kFilePathSep = '/';
+#if defined(__linux__) || defined(__sun)
+	static size_t _sa_len(const struct sockaddr *addr)
+		{
+		if (addr->sa_family == AF_INET) return (sizeof(struct sockaddr_in));
+		else if (addr->sa_family == AF_INET6) return (sizeof(struct sockaddr_in6));
+		else return (sizeof(struct sockaddr));
+		}
+
+#   define SA_LEN(addr) (_sa_len(addr))
+#else
 	#define SA_LEN(addr) ((addr)->sa_len)
 #endif
+#endif
 
 #if (TEST_NEW_CLIENTSTUB && !defined(__APPLE_API_PRIVATE))
 #define __APPLE_API_PRIVATE 1
