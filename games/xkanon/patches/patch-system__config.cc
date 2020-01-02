$NetBSD: patch-system__config.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Appease LP64 warnings.

--- system_config.cc.orig	2008-01-06 06:20:00.000000000 +0000
+++ system_config.cc
@@ -536,14 +536,14 @@ public:
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
