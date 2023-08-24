$NetBSD: patch-usr.sbin_smtpd_proxy.c,v 1.1 2023/08/24 15:26:40 vins Exp $

Rename local variables to avoid name clash on SmartOS.

--- usr.sbin/smtpd/proxy.c.orig	2020-05-21 19:06:04.000000000 +0000
+++ usr.sbin/smtpd/proxy.c
@@ -341,7 +341,7 @@ proxy_translate_ss(struct proxy_session
 {
 	struct sockaddr_in *sin = (struct sockaddr_in *) &s->ss;
 	struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *) &s->ss;
-	struct sockaddr_un *sun = (struct sockaddr_un *) &s->ss;
+	struct sockaddr_un *lsun = (struct sockaddr_un *) &s->ss;
 	size_t sun_len;
 
 	switch (s->hdr.fam) {
@@ -370,13 +370,13 @@ proxy_translate_ss(struct proxy_session
 		memset(&s->ss, 0, sizeof(s->ss));
 		sun_len = strnlen(s->addr.un.src_addr,
 		    sizeof(s->addr.un.src_addr));
-		if (sun_len > sizeof(sun->sun_path)) {
+		if (sun_len > sizeof(lsun->sun_path)) {
 			proxy_error(s, "address translation", "Unix socket path"
 			    " longer than supported");
 			return (-1);
 		}
-		sun->sun_family = AF_UNIX;
-		memcpy(sun->sun_path, s->addr.un.src_addr, sun_len);
+		lsun->sun_family = AF_UNIX;
+		memcpy(lsun->sun_path, s->addr.un.src_addr, sun_len);
 		break;
 
 	default:
