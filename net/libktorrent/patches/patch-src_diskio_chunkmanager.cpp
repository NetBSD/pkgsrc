$NetBSD: patch-src_diskio_chunkmanager.cpp,v 1.1 2020/05/14 19:14:16 joerg Exp $

Can't match when switching over an unsigned variable.

--- src/diskio/chunkmanager.cpp.orig	2020-05-12 13:42:42.467062945 +0000
+++ src/diskio/chunkmanager.cpp
@@ -527,10 +527,6 @@ namespace bt
 					//tf.setDoNotDownload(true);
 					tf.setPriority(EXCLUDED);
 					break;
-				case ONLY_SEED_PRIORITY:
-				case -1:
-					tf.setPriority(ONLY_SEED_PRIORITY);
-					break;
 				default:
 					tf.setPriority(LAST_PRIORITY);
 					break;
