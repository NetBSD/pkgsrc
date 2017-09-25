$NetBSD: patch-lib_mp4_ctab.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- lib/mp4/ctab.c.orig	2017-09-25 14:45:45.288644518 +0000
+++ lib/mp4/ctab.c
@@ -22,7 +22,7 @@ int quicktime_ctab_delete(quicktime_ctab
 	return 0;
 }
 
-int quicktime_ctab_dump(quicktime_ctab_t *ctab)
+void quicktime_ctab_dump(quicktime_ctab_t *ctab)
 {
 	int i;
 	printf(" color table\n");
