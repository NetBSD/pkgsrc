$NetBSD: patch-utils_cups-browsed.c,v 1.7 2022/09/18 14:41:07 he Exp $

Fix a rather obvious bug, should pass length of allocation...

--- utils/cups-browsed.c.orig	2022-04-11 19:56:40.000000000 +0000
+++ utils/cups-browsed.c
@@ -10242,7 +10242,7 @@ static void resolve_callback(AvahiServic
 		   address->proto == AVAHI_PROTO_INET6 &&
 		   interface != AVAHI_IF_UNSPEC &&
 		   IPBasedDeviceURIs != IP_BASED_URIS_IPV4_ONLY) {
-	  strncpy(addrstr, "[v1.", sizeof(addrstr) - 1);
+	  strncpy(addrstr, "[v1.", 255); /* size of allocation - 1 for null */
 	  avahi_address_snprint(addrstr + 4, 256 - 6, address);
 	  addrlen = strlen(addrstr + 4);
 	  addr->sa_family = AF_INET6;
