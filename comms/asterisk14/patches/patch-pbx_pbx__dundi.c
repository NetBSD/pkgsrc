$NetBSD: patch-pbx_pbx__dundi.c,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- pbx/pbx_dundi.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ pbx/pbx_dundi.c
@@ -47,7 +47,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <pthread.h>
 #include <net/if.h>
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__) || defined(__DragonFly__)
 #include <net/if_dl.h>
 #include <ifaddrs.h>
 #include <signal.h>
@@ -885,7 +885,7 @@ static int cache_save_hint(dundi_eid *ei
 
 	time(&timeout);
 	timeout += expiration;
-	snprintf(data, sizeof(data), "%ld|", (long)(timeout));
+	snprintf(data, sizeof(data), "%jd|", (intmax_t)(timeout));
 
 	ast_db_put("dundi/cache", key1, data);
 	ast_debug(1, "Caching hint at '%s'\n", key1);
@@ -921,7 +921,7 @@ static int cache_save(dundi_eid *eidpeer
 	/* Build request string */
 	time(&timeout);
 	timeout += expiration;
-	snprintf(data, sizeof(data), "%ld|", (long)(timeout));
+	snprintf(data, sizeof(data), "%jd|", (intmax_t)(timeout));
 	for (x=start;x<req->respcount;x++) {
 		/* Skip anything with an illegal pipe in it */
 		if (strchr(req->dr[x].dest, '|'))
@@ -2166,7 +2166,7 @@ static void check_password(void)
 
 	time(&now);
 #if 0
-	printf("%ld/%ld\n", now, rotatetime);
+	printf("%jd/%jd\n", now, rotatetime);
 #endif
 	if ((now - rotatetime) >= 0) {
 		/* Time to rotate keys */
