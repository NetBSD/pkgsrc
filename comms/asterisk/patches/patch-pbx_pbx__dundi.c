$NetBSD: patch-pbx_pbx__dundi.c,v 1.2 2015/05/19 07:52:14 jnemeth Exp $

--- pbx/pbx_dundi.c.orig	2014-05-09 22:28:40.000000000 +0000
+++ pbx/pbx_dundi.c
@@ -38,7 +38,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <pthread.h>
 #include <net/if.h>
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__) || defined(__DragonFly__)
 #include <net/if_dl.h>
 #include <ifaddrs.h>
 #include <signal.h>
@@ -876,7 +876,7 @@ static int cache_save_hint(dundi_eid *ei
 
 	time(&timeout);
 	timeout += expiration;
-	snprintf(data, sizeof(data), "%ld|", (long)(timeout));
+	snprintf(data, sizeof(data), "%jd|", (intmax_t)(timeout));
 
 	ast_db_put("dundi/cache", key1, data);
 	ast_debug(1, "Caching hint at '%s'\n", key1);
@@ -912,7 +912,7 @@ static int cache_save(dundi_eid *eidpeer
 	/* Build request string */
 	time(&timeout);
 	timeout += expiration;
-	snprintf(data, sizeof(data), "%ld|", (long)(timeout));
+	snprintf(data, sizeof(data), "%jd|", (intmax_t)(timeout));
 	for (x=start;x<req->respcount;x++) {
 		/* Skip anything with an illegal pipe in it */
 		if (strchr(req->dr[x].dest, '|'))
@@ -2157,7 +2157,7 @@ static void check_password(void)
 
 	time(&now);
 #if 0
-	printf("%ld/%ld\n", now, rotatetime);
+	printf("%jd/%jd\n", now, rotatetime);
 #endif
 	if ((now - rotatetime) >= 0) {
 		/* Time to rotate keys */
