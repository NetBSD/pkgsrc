$NetBSD: patch-bin_named_server.c,v 1.1 2019/04/30 02:51:38 taca Exp $

* Disable checking working directory is writable as BIND_USER in NetBSD
  base system.

--- bin/named/server.c.orig	2019-04-06 01:47:33.000000000 +0000
+++ bin/named/server.c
@@ -8272,6 +8272,7 @@ load_configuration(const char *filename,
 		ns_os_changeuser();
 	}
 
+#if 0
 	/*
 	 * Check that the working directory is writable.
 	 */
@@ -8280,6 +8281,7 @@ load_configuration(const char *filename,
 			      NS_LOGMODULE_SERVER, ISC_LOG_ERROR,
 			      "the working directory is not writable");
 	}
+#endif
 
 #ifdef HAVE_LMDB
 	/*
