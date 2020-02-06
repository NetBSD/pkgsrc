$NetBSD: patch-config.h,v 1.1 2020/02/06 22:39:38 roy Exp $

Allow CONFIRM to check all addresses on the link.

--- config.h.orig	2008-06-15 07:48:41.000000000 +0000
+++ config.h
@@ -33,6 +33,12 @@
 TAILQ_HEAD(ia_conflist, ia_conf);
 TAILQ_HEAD(pifc_list, prefix_ifconf);
 
+struct if_addr {
+	TAILQ_ENTRY(if_addr) link;
+	struct in6_addr addr;
+};
+TAILQ_HEAD(if_addr_list, if_addr);
+
 struct dhcp6_poolspec {
 	char* name;
 	u_int32_t pltime;
@@ -67,8 +73,7 @@ struct dhcp6_if {
 	char *ifname;
 	unsigned int ifid;
 	u_int32_t linkid;	/* to send link-local packets */
-	/* multiple global address configuration is not supported now */
-	struct in6_addr addr; 	/* global address */
+	struct if_addr_list addr_list;
 
 	/* configuration parameters */
 	u_long send_flags;
