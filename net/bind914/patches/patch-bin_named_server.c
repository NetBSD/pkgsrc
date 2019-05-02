$NetBSD: patch-bin_named_server.c,v 1.2 2019/05/02 13:29:53 taca Exp $

* Disable checking working directory is writable as BIND_USER in NetBSD
  base system.

--- bin/named/server.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ bin/named/server.c
@@ -6464,6 +6464,7 @@ directory_callback(const char *clausenam
 			    "option 'directory' contains relative path '%s'",
 			    directory);
 
+#if 0
 	if (!isc_file_isdirwritable(directory)) {
 		isc_log_write(named_g_lctx, NAMED_LOGCATEGORY_GENERAL,
 			      NAMED_LOGMODULE_SERVER, ISC_LOG_ERROR,
@@ -6471,6 +6472,7 @@ directory_callback(const char *clausenam
 			      directory);
 		return (ISC_R_NOPERM);
 	}
+#endif
 
 	result = isc_dir_chdir(directory);
 	if (result != ISC_R_SUCCESS) {
@@ -8864,6 +8866,7 @@ load_configuration(const char *filename,
 		named_os_changeuser();
 	}
 
+#if 0
 	/*
 	 * Check that the working directory is writable.
 	 */
@@ -8874,6 +8877,7 @@ load_configuration(const char *filename,
 		result = ISC_R_NOPERM;
 		goto cleanup;
 	}
+#endif
 
 #ifdef HAVE_LMDB
 	/*
