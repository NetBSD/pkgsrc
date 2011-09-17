$NetBSD: patch-saslauthd_saslcache.c,v 1.1 2011/09/17 11:32:02 obache Exp $

* fixes build with gcc-4.

--- saslauthd/saslcache.c.orig	2003-03-28 19:59:24.000000000 +0000
+++ saslauthd/saslcache.c
@@ -137,7 +137,7 @@ int main(int argc, char **argv) {
 	}
 
 	table_stats = shm_base + 64;
-	(char *)table = (char *)table_stats + 128;
+	table = (struct bucket *)((char *)table_stats + 128);
 
 	if (dump_stat_info == 0 && dump_user_info == 0)
 		dump_stat_info = 1;
