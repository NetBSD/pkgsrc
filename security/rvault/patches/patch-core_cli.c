$NetBSD: patch-core_cli.c,v 1.1 2020/05/19 14:00:57 joerg Exp $

--- core/cli.c.orig	2020-05-16 18:22:17.498052418 +0000
+++ core/cli.c
@@ -208,7 +208,7 @@ mount_vault(const char *datapath, const 
 		switch (ch) {
 		case 'c':
 			comp = optarg && (
-			    atoi(optarg) || tolower(optarg[0]) == 'y'
+			    atoi(optarg) || tolower((unsigned char)optarg[0]) == 'y'
 			);
 			break;
 		case 'd':
