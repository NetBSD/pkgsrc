$NetBSD: patch-src_libbdplus_bdsvm_segment.c,v 1.1 2014/01/08 23:07:09 wiz Exp $

fseeko is a Linuxism.

--- src/libbdplus/bdsvm/segment.c.orig	2013-12-18 12:13:09.000000000 +0000
+++ src/libbdplus/bdsvm/segment.c
@@ -950,7 +950,7 @@ int32_t segment_patchfile(conv_table_t *
                        offset);
             }
 
-            if (fseeko(fd, offset, SEEK_SET)) {
+            if (fseek(fd, offset, SEEK_SET)) {
                 printf("Seek to offset %"PRIx64" failed. Stopping at table %d, segment %d, entry %d.\n",
                        offset, table, currseg, currentry);
                 return -1;
@@ -975,7 +975,7 @@ int32_t segment_patchfile(conv_table_t *
                        offset);
             }
 
-            if (fseeko(fd, offset, SEEK_SET)) {
+            if (fseek(fd, offset, SEEK_SET)) {
                 printf("Seek to offset %"PRIx64" failed. Stopping at table %d, segment %d, entry %d.\n",
                        offset, table, currseg, currentry);
                 return -1;
