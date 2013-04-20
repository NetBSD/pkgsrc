$NetBSD: patch-main.c,v 1.1 2013/04/20 09:40:49 apb Exp $

Fix parsing of "-k" and "--reposurgeon" command line options.
Patch has been sent upstream, in email dated 25 Mar 2013.

--- main.c.orig	2013-01-14 00:17:55.000000000 +0000
+++ main.c
@@ -410,10 +410,10 @@ main (int argc, char **argv)
 	    { "commit-time-window", 1, 0, 'w' },
 	    { "author-map",         1, 0, 'A' },
 	    { "revision-map",       1, 0, 'R' },
-	    { "reposurgeon",        1, 0, 'r' },
+	    { "reposurgeon",        0, 0, 'r' },
             { "graph",              0, 0, 'g' },
 	};
-	int c = getopt_long(argc, argv, "+hVw:grvA:R:T", options, NULL);
+	int c = getopt_long(argc, argv, "+hkVw:grvA:R:T", options, NULL);
 	if (c < 0)
 	    break;
 	switch (c) {
