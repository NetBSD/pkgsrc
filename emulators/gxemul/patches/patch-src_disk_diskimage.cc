$NetBSD: patch-src_disk_diskimage.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/disk/diskimage.cc.orig	2014-08-17 08:45:14.000000000 +0000
+++ src/disk/diskimage.cc
@@ -732,7 +732,7 @@ int diskimage_add(struct machine *machin
 				if (*fname == ':' || *fname == ';')
 					fname ++;
 				if (override_base_offset < 0) {
-					fatal("Bad base offset: %"PRIi64
+					fatal("Bad base offset: %" PRIi64
 					    "\n", override_base_offset);
 					exit(1);
 				}
@@ -1132,4 +1132,3 @@ void diskimage_dump_info(struct machine 
 		d = d->next;
 	}
 }
-
