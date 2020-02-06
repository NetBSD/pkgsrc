$NetBSD: patch-dhcp6s.c,v 1.1 2020/02/06 22:39:38 roy Exp $

Allow CONFIRM to check all addresses on the link.

--- dhcp6s.c.orig	2008-06-15 07:51:57.000000000 +0000
+++ dhcp6s.c
@@ -2237,10 +2237,20 @@ react_confirm(ifp, pi, dh6, len, optinfo
 		    iaaddr = TAILQ_NEXT(iaaddr, link)) {
 		
 			struct in6_addr *confaddr = &iaaddr->val_statefuladdr6.addr;
-			struct in6_addr *linkaddr;
+			struct in6_addr *linkaddr = NULL;
 			struct sockaddr_in6 *src = (struct sockaddr_in6 *)from;
+			struct if_addr *ia;
 
-			if (!IN6_IS_ADDR_LINKLOCAL(&src->sin6_addr)) {
+			/* CONFIRM should match an interface address */
+			TAILQ_FOREACH(ia, &ifp->addr_list, link) {
+				if (memcmp(&ia->addr, confaddr, 8) == 0) {
+					linkaddr = &ia->addr;
+					break;
+				}
+			}
+
+			if (linkaddr == NULL &&
+			    !IN6_IS_ADDR_LINKLOCAL(&src->sin6_addr)) {
 				/* CONFIRM is relayed via a DHCP-relay */
 				struct relayinfo *relayinfo;
 
@@ -2249,20 +2259,19 @@ react_confirm(ifp, pi, dh6, len, optinfo
 					    "no link-addr found");
 					goto fail;
 				}
-				relayinfo = TAILQ_LAST(relayinfohead, relayinfolist);
+				relayinfo = TAILQ_LAST(relayinfohead,
+				    relayinfolist);
 
-				/* XXX: link-addr is supposed to be a global address */
-				linkaddr = &relayinfo->linkaddr;
-			} else {
-				/* CONFIRM is directly arrived */
-				linkaddr = &ifp->addr;
+				/* XXX: link-addr is supposed to be a
+				 * global address */
+				if (!memcmp(&relayinfo->linkaddr, confaddr, 8))
+					linkaddr = &relayinfo->linkaddr;
 			}
 
-			if (memcmp(linkaddr, confaddr, 8) != 0) {
+			if (linkaddr == NULL) {
 				dprintf(LOG_INFO, FNAME,
 				    "%s does not seem to belong to %s's link",
-				    in6addr2str(confaddr, 0),
-				    in6addr2str(linkaddr, 0));
+				    in6addr2str(confaddr, 0), ifp->ifname);
 				stcode = DH6OPT_STCODE_NOTONLINK;
 				goto send_reply;
 			}
