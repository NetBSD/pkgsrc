$NetBSD: patch-hdhomerun__sock__posix.c,v 1.1 2014/05/10 22:41:02 jakllsch Exp $

--- hdhomerun_sock_posix.c.orig	2014-01-16 19:01:59.000000000 +0000
+++ hdhomerun_sock_posix.c
@@ -86,7 +86,7 @@ int hdhomerun_local_ip_info(struct hdhom
 	}
 
 	char *ptr = ifc.ifc_buf;
-	char *end = ifc.ifc_buf + ifc.ifc_len;
+	char *end = (char *)ifc.ifc_buf + ifc.ifc_len;
 
 	int count = 0;
 	while (ptr < end) {
