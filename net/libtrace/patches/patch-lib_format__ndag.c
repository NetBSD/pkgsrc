$NetBSD: patch-lib_format__ndag.c,v 1.1 2019/11/20 21:00:47 adam Exp $

Fix building on systems without multicast join group.

--- lib/format_ndag.c.orig	2019-11-20 15:53:12.972523619 +0000
+++ lib/format_ndag.c
@@ -181,6 +181,7 @@ static uint8_t check_ndag_header(char *m
 static int join_multicast_group(char *groupaddr, char *localiface,
         char *portstr, uint16_t portnum, struct addrinfo **srcinfo) {
 
+#ifdef MCAST_JOIN_GROUP
         struct addrinfo hints;
         struct addrinfo *gotten;
         struct addrinfo *group;
@@ -288,6 +289,9 @@ static int join_multicast_group(char *gr
 sockcreateover:
         freeaddrinfo(group);
         return sock;
+#else
+	return -1;
+#endif
 }
 
 
