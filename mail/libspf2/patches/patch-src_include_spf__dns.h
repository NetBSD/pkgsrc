$NetBSD: patch-src_include_spf__dns.h,v 1.1 2023/06/02 15:57:57 schmonz Exp $

Define NETDB_SUCCESS on musl libc (such as Void Linux).

--- src/include/spf_dns.h.orig	2021-06-09 05:43:12.000000000 +0000
+++ src/include/spf_dns.h
@@ -105,6 +105,9 @@ typedef int	ns_type;
 #define	NO_RECOVERY		3		/**< invalid/unimplmeneted query	*/
 #define	NO_DATA			4		/**< host found, but no RR of req type*/
 #endif
+#if !defined(NETDB_SUCCESS)
+#define NETDB_SUCCESS	0
+#endif
 typedef int SPF_dns_stat_t;
 
 typedef struct SPF_dns_server_struct SPF_dns_server_t;
