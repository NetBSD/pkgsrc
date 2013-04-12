$NetBSD: patch-getopt.c,v 1.1 2013/04/12 20:00:10 adam Exp $

--- getopt.c.orig	2013-04-12 15:23:09.000000000 +0000
+++ getopt.c
@@ -399,9 +399,11 @@ int main(int argc, char *argv[])
 	while ((opt =
 		getopt_long(argc, argv, shortopts, longopts, NULL)) != EOF)
 		switch (opt) {
+#ifndef __NetBSD__
 		case 'a':
 			getopt_long_fp = getopt_long_only;
 			break;
+#endif
 		case 'h':
 			print_help();
 		case 'o':
