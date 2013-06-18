$NetBSD: patch-lib_mount__v7fs.c,v 1.1 2013/06/18 18:52:10 wiz Exp $

Function returning void shouldn't return values.

--- lib/mount_v7fs.c.orig	2013-06-01 12:54:14.000000000 +0000
+++ lib/mount_v7fs.c
@@ -155,13 +155,13 @@ mount_v7fs_parseargs(int argc, char **ar
 		case '?':
 
 		default:
-			return 1;
+			return;
 		}
 	argc -= optind;
 	argv += optind;
 
 	if (argc != 2)
-		return 1;
+		return;
 
 	pathadj(argv[0], canon_dev);
 	args->endian = endian;
