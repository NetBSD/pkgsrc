$NetBSD: patch-system_system__config.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

Fix casts in printfs that cause build error on LP64 machines.

--- system/system_config.cc.orig	2008-08-31 09:52:12.000000000 +0000
+++ system/system_config.cc
@@ -367,14 +367,14 @@ public:
 			fprintf(f, ") ");
 		}
 		if (old_data) {
-			fprintf(f, "old %08x(%d", (unsigned int)(old_data), old_data[0]);
+			fprintf(f, "old %08lx(%d", (unsigned long)(old_data), old_data[0]);
 			int i;for (i=1; i<item_deal; i++) {
 				fprintf(f, ",%d",old_data[i]);
 			}
 			fprintf(f, ") ");
 		}
 		if (new_data) {
-			fprintf(f, "new %08x(%d", (unsigned int)(new_data), new_data[0]);
+			fprintf(f, "new %08lx(%d", (unsigned long)(new_data), new_data[0]);
 			int i;for (i=1; i<item_deal; i++) {
 				fprintf(f, ",%d",new_data[i]);
 			}
