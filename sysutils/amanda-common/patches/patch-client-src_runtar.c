$NetBSD: patch-client-src_runtar.c,v 1.1 2025/10/17 07:55:17 kikadf Exp $

* Fix CVE-2022-37705,
  https://github.com/zmanda/amanda/commit/497410c7555376795f324e5bd2cbed7742219099

--- client-src/runtar.c.orig	2025-10-17 07:41:49.922060195 +0000
+++ client-src/runtar.c
@@ -183,9 +183,9 @@ main(
 		g_str_has_prefix(argv[i],"--newer") ||
 		g_str_has_prefix(argv[i],"--exclude-from") ||
 		g_str_has_prefix(argv[i],"--files-from")) {
-		/* Accept theses options with the following argument */
-		good_option += 2;
+		good_option++;
 	    } else if (argv[i][0] != '-') {
+		/* argument values are accounted for here */
 		good_option++;
 	    }
 	}
