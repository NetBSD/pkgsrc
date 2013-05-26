$NetBSD: patch-bin_cobcrun.c,v 1.1 2013/05/26 04:13:05 ryoon Exp $

* Some patform has no getopt_long_only.

--- bin/cobcrun.c.orig	2013-02-02 20:44:08.000000000 +0000
+++ bin/cobcrun.c
@@ -107,7 +107,7 @@ process_command_line (int argc, char *ar
 		return 99;
 	}
 
-	c = getopt_long_only (argc, argv, short_options, long_options, &idx);
+	c = getopt_long (argc, argv, short_options, long_options, &idx);
 	if (c > 0) {
 		switch (c) {
 		case '?':
