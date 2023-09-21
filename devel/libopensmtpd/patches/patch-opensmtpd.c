$NetBSD: patch-opensmtpd.c,v 1.1 2023/09/21 10:57:40 vins Exp $

Rename local variables to avoid name clash on SmartOS.

--- opensmtpd.c.orig	2021-06-01 11:31:56.000000000 +0000
+++ opensmtpd.c
@@ -2001,7 +2001,7 @@ osmtpd_addrtoss(char *addr, struct socka
 	const char *errstr = NULL;
 	struct sockaddr_in *sin;
 	struct sockaddr_in6 *sin6;
-	struct sockaddr_un *sun;
+	struct sockaddr_un *lsun;
 	size_t n;
 
 	if (addr[0] == '[') {
@@ -2048,10 +2048,10 @@ osmtpd_addrtoss(char *addr, struct socka
 			    linedup);
 		}
 	} else if (strncasecmp(addr, "unix:", 5) == 0) {
-		sun = (struct sockaddr_un *)ss;
-		sun->sun_family = AF_UNIX;
-		if (strlcpy(sun->sun_path, addr,
-		    sizeof(sun->sun_path)) >= sizeof(sun->sun_path)) {
+		lsun = (struct sockaddr_un *)ss;
+		lsun->sun_family = AF_UNIX;
+		if (strlcpy(lsun->sun_path, addr,
+		    sizeof(lsun->sun_path)) >= sizeof(lsun->sun_path)) {
 			osmtpd_errx(1, "Invalid line received: address too "
 			    "long (%s): %s", addr, linedup);
 		}
