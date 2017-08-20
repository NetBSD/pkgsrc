$NetBSD: patch-base_utils.c,v 1.1 2017/08/20 06:59:16 manu Exp $

From upstream https://github.com/NagiosEnterprises/nagioscore/pull/417

Once nagios is done with a file in the checkresults directory,
it deletes it. This was done with a relative file path, causing
failures if nagios working directory is not the checkresults
directory. As a consequence, old result file remained intact,
causing system slowdowns as the directory grew and nagios spent
more and more time attempting to clean it up.

The fix is just to use an absolute path, so that it works
regardeless of current directory setting.

From 42f115ad87cf9113252f1d2ab88fc822ce052f56 Mon Sep 17 00:00:00 2001
From: Bryan Heden <bheden@nagios.com>
Date: Sat, 19 Aug 2017 12:02:34 -0500
Subject: [PATCH] use absolute paths when deleting in checkresults directory.
 github pull #417

---
 base/utils.c | 13 +++++++++----
 1 file changed, 9 insertions(+), 4 deletions(-)

diff --git base/utils.c base/utils.c
index f2286c73..8116ebf9 100644
--- base/utils.c
+++ base/utils.c
@@ -2133,7 +2133,11 @@ int process_check_result_queue(char *dirname) {
 
 			/* if the file is too old, we delete it */
 			if (stat_buf.st_mtime + max_check_result_file_age < time(NULL)) {
-				delete_check_result_file(dirfile->d_name);
+
+				if (delete_check_result_file(file) != OK 
+					&& delete_check_result_file(dirfile->d_name) != OK)
+						logit(NSLOG_RUNTIME_WARNING, TRUE, "Error: Unable to delete '%s' or '%s'!", file, dirfile->d_name);
+
 				continue;
 				}
 
@@ -2363,16 +2367,17 @@ int process_check_result_file(char *fname) {
 /* deletes as check result file, as well as its ok-to-go file */
 int delete_check_result_file(char *fname) {
 	char *temp_buffer = NULL;
+	int result = OK;
 
 	/* delete the result file */
-	unlink(fname);
+	result = unlink(fname);
 
 	/* delete the ok-to-go file */
 	asprintf(&temp_buffer, "%s.ok", fname);
-	unlink(temp_buffer);
+	result |= unlink(temp_buffer);
 	my_free(temp_buffer);
 
-	return OK;
+	return result;
 	}
 
 
