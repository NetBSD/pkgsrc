$NetBSD: patch-cpp.c,v 1.1 2015/09/30 16:39:45 richard Exp $
patch borrowed from libreoffice for more information in options processing.
--- cpp.c.orig	2011-08-09 05:13:15.000000000 +0000
+++ cpp.c
@@ -2464,7 +2464,9 @@ static int parse_opt(int argc, char *arg
 			warning(-1, "unknown option '%s'", argv[i]);
 	} else {
 		if (filename != 0) {
-			error(-1, "spurious filename '%s'", argv[i]);
+			error(-1, "spurious duplicate filename '%s' - vs. '%s'",
+			    argv[i], filename);
+
 			return 2;
 		}
 		filename = argv[i];
