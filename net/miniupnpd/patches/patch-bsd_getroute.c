$NetBSD: patch-bsd_getroute.c,v 1.1 2013/10/21 10:06:57 fhajny Exp $

use the SA_LEN wrapper
--- bsd/getroute.c.orig	2013-02-06 13:14:42.000000000 +0000
+++ bsd/getroute.c
@@ -83,7 +83,7 @@ get_src_for_route_to(const struct sockad
 				sa = (struct sockaddr *)p;
 				sockaddr_to_string(sa, tmp, sizeof(tmp));
 				syslog(LOG_DEBUG, "type=%d sa_len=%d sa_family=%d %s",
-				       i, sa->sa_len, sa->sa_family, tmp);
+				       i, SA_LEN(sa), sa->sa_family, tmp);
 				if((i == RTA_DST || i == RTA_GATEWAY) &&
 				   (src_len && src)) {
 					size_t len = 0;
@@ -113,7 +113,7 @@ get_src_for_route_to(const struct sockad
 						*index = sdl->sdl_index;
 				}
 #endif
-				p += sa->sa_len;
+				p += SA_LEN(sa);
 			}
 		}
 	}
