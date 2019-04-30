$NetBSD: patch-bin_named_server.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Disable checking working directory is writable as BIND_USER in NetBSD
  base system.

--- bin/named/server.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ bin/named/server.c
@@ -8864,6 +8864,7 @@ load_configuration(const char *filename,
 		named_os_changeuser();
 	}
 
+#if 0
 	/*
 	 * Check that the working directory is writable.
 	 */
@@ -8874,6 +8875,7 @@ load_configuration(const char *filename,
 		result = ISC_R_NOPERM;
 		goto cleanup;
 	}
+#endif
 
 #ifdef HAVE_LMDB
 	/*
