$NetBSD: patch-bin_named_server.c,v 1.2 2024/12/13 17:29:56 taca Exp $

* Take from NetBSD base, especially disable checking working directory
  is writable as BIND_USER in NetBSD base system.

--- bin/named/server.c.orig	2024-12-03 13:00:51.226928524 +0000
+++ bin/named/server.c
@@ -7161,12 +7161,14 @@ directory_callback(const char *clausenam
 			    directory);
 	}
 
+#if 0
 	if (!isc_file_isdirwritable(directory)) {
 		isc_log_write(named_g_lctx, NAMED_LOGCATEGORY_GENERAL,
 			      NAMED_LOGMODULE_SERVER, ISC_LOG_ERROR,
 			      "directory '%s' is not writable", directory);
 		return ISC_R_NOPERM;
 	}
+#endif
 
 	result = isc_dir_chdir(directory);
 	if (result != ISC_R_SUCCESS) {
@@ -9560,6 +9562,7 @@ load_configuration(const char *filename,
 		named_os_changeuser();
 	}
 
+#if 0
 	/*
 	 * Check that the working directory is writable.
 	 */
@@ -9570,7 +9573,7 @@ load_configuration(const char *filename,
 		result = ISC_R_NOPERM;
 		goto cleanup;
 	}
-
+#endif
 #ifdef HAVE_LMDB
 	/*
 	 * Reopen NZD databases.
