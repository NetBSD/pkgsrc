$NetBSD: patch-src_control_control.c,v 1.1 2012/12/08 00:15:26 jakllsch Exp $

--- src/control/control.c.orig	2012-11-23 23:23:21.000000000 +0000
+++ src/control/control.c
@@ -594,7 +594,9 @@ void dt_control_init(dt_control_t *s)
 
       // selected_images should have a primary key. add it if it's missing:
       int is_in_primary_key = 0;
+#if 0
       sqlite3_table_column_metadata(dt_database_get(darktable.db), NULL, "selected_images", "imgid", NULL, NULL, NULL, &is_in_primary_key, NULL);
+#endif
       if(is_in_primary_key == 0)
       {
         sqlite3_exec(dt_database_get(darktable.db),
