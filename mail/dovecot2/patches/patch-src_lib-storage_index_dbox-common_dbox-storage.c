$NetBSD: patch-src_lib-storage_index_dbox-common_dbox-storage.c,v 1.1 2023/09/24 18:03:09 schmonz Exp $

Apply upstream PR #211 to fix macOS build.

--- src/lib-storage/index/dbox-common/dbox-storage.c.orig	2023-09-14 13:17:46.000000000 +0000
+++ src/lib-storage/index/dbox-common/dbox-storage.c
@@ -293,8 +293,8 @@ int dbox_mailbox_list_cleanup(struct mai
 		   if the directory exists. In case, get also the ctime */
 		struct stat stats;
 		if (stat(path, &stats) == 0) {
-			last_temp_file_scan = stats.st_atim.tv_sec;
-			change_time = stats.st_ctim.tv_sec;
+			last_temp_file_scan = ST_ATIME_SEC(stats);
+			change_time = ST_CTIME_SEC(stats);
 		} else {
 			if (errno != ENOENT)
 				e_error(user->event, "stat(%s) failed: %m", path);
