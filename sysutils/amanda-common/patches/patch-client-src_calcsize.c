$NetBSD: patch-client-src_calcsize.c,v 1.1 2025/10/17 07:55:17 kikadf Exp $

* Fix CVE-2022-37703,
  https://github.com/zmanda/amanda/commit/cf01041d34b830fc8bfe87346a9a1aa092d76820

--- client-src/calcsize.c.orig	2025-10-17 07:36:29.435296433 +0000
+++ client-src/calcsize.c
@@ -434,7 +434,6 @@ traverse_dirs(
 	    continue;
 	}
 	if((d = opendir(dirname)) == NULL) {
-	    perror(dirname);
 	    continue;
 	}
 
