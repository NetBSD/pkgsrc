$NetBSD: patch-if.c,v 1.1 2020/02/06 22:39:38 roy Exp $

Allow CONFIRM to check all addresses on the link.

--- if.c.orig	2008-06-15 07:48:43.000000000 +0000
+++ if.c
@@ -58,6 +58,7 @@ ifinit(ifname)
 	char *ifname;
 {
 	struct dhcp6_if *ifp;
+	struct if_addr *ia;
 
 	if ((ifp = find_ifconfbyname(ifname)) != NULL) {
 		dprintf(LOG_NOTICE, FNAME, "duplicated interface: %s", ifname);
@@ -66,11 +67,12 @@ ifinit(ifname)
 
 	if ((ifp = malloc(sizeof(*ifp))) == NULL) {
 		dprintf(LOG_ERR, FNAME, "malloc failed");
-		goto fail;
+		return (NULL);
 	}
 	memset(ifp, 0, sizeof(*ifp));
 
 	TAILQ_INIT(&ifp->event_list);
+	TAILQ_INIT(&ifp->addr_list);
 
 	if ((ifp->ifname = strdup(ifname)) == NULL) {
 		dprintf(LOG_ERR, FNAME, "failed to copy ifname");
@@ -109,7 +111,14 @@ ifinit(ifname)
 			if (IN6_IS_ADDR_LINKLOCAL(&sin6->sin6_addr))
 				continue;
 
-			ifp->addr = sin6->sin6_addr;
+			ia = malloc(sizeof(*ia));
+			if (ia == NULL) {
+				dprintf(LOG_ERR, FNAME, "malloc failed: %s",
+				    strerror(errno));
+				goto fail;
+			}
+			ia->addr = sin6->sin6_addr;
+			TAILQ_INSERT_TAIL(&ifp->addr_list, ia, link);
 		}
 
 		freeifaddrs(ifap);
@@ -122,6 +131,10 @@ ifinit(ifname)
   fail:
 	if (ifp->ifname != NULL)
 		free(ifp->ifname);
+	while ((ia = TAILQ_FIRST(&ifp->addr_list)) != NULL) {
+		TAILQ_REMOVE(&ifp->addr_list, ia, link);
+		free(ia);
+	}
 	free(ifp);
 	return (NULL);
 }
