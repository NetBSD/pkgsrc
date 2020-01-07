$NetBSD: patch-rdnssd_rdnssd.h,v 1.2 2020/01/07 11:08:14 kim Exp $

Don't define nd_opt_rdnss on NetBSD.

--- rdnss/rdnssd.h.orig	2011-10-17 15:35:11.000000000 +0000
+++ rdnss/rdnssd.h
@@ -32,6 +32,7 @@ extern const rdnss_src_t rdnss_netlink, 
 #define ND_OPT_RDNSS 25
 #define ND_OPT_DNSSL 31
 
+#if !defined(__NetBSD__)
 struct nd_opt_rdnss
 {
 	uint8_t nd_opt_rdnss_type;
@@ -49,6 +50,7 @@ struct nd_opt_dnssl
 	uint32_t nd_opt_dnssl_lifetime;
 	/* followed by one or more domain names */
 };
+#endif /* !defined(__NetBSD__) */
 
 # ifdef __cplusplus
 extern "C" {
