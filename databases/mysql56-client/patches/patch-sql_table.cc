$NetBSD: patch-sql_table.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/table.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/table.cc
@@ -1076,7 +1076,7 @@ static int open_binary_frm(THD *thd, TAB
   }
   share->db_record_offset= 1;
   /* Set temporarily a good value for db_low_byte_first */
-  share->db_low_byte_first= test(legacy_db_type != DB_TYPE_ISAM);
+  share->db_low_byte_first= my_test(legacy_db_type != DB_TYPE_ISAM);
   error=4;
   share->max_rows= uint4korr(head+18);
   share->min_rows= uint4korr(head+22);
@@ -1206,7 +1206,7 @@ static int open_binary_frm(THD *thd, TAB
                                          keyinfo->comment.length);
       strpos+= 2 + keyinfo->comment.length;
     } 
-    DBUG_ASSERT(test(keyinfo->flags & HA_USES_COMMENT) == 
+    DBUG_ASSERT(my_test(keyinfo->flags & HA_USES_COMMENT) == 
                (keyinfo->comment.length > 0));
   }
 
@@ -2374,9 +2374,9 @@ partititon_err:
   else if (outparam->file)
   {
     handler::Table_flags flags= outparam->file->ha_table_flags();
-    outparam->no_replicate= ! test(flags & (HA_BINLOG_STMT_CAPABLE
+    outparam->no_replicate= ! my_test(flags & (HA_BINLOG_STMT_CAPABLE
                                             | HA_BINLOG_ROW_CAPABLE))
-                            || test(flags & HA_HAS_OWN_BINLOGGING);
+                            || my_test(flags & HA_HAS_OWN_BINLOGGING);
   }
   else
   {
@@ -2928,7 +2928,7 @@ File create_frm(THD *thd, const char *na
     /* header */
     fileinfo[0]=(uchar) 254;
     fileinfo[1]= 1;
-    fileinfo[2]= FRM_VER+3+ test(create_info->varchar);
+    fileinfo[2]= FRM_VER+3+ my_test(create_info->varchar);
 
     fileinfo[3]= (uchar) ha_legacy_type(
           ha_checktype(thd,ha_legacy_type(create_info->db_type),0,0));
@@ -2948,7 +2948,7 @@ File create_frm(THD *thd, const char *na
     */
     for (i= 0; i < keys; i++)
     {
-      DBUG_ASSERT(test(key_info[i].flags & HA_USES_COMMENT) == 
+      DBUG_ASSERT(my_test(key_info[i].flags & HA_USES_COMMENT) == 
                  (key_info[i].comment.length > 0));
       if (key_info[i].flags & HA_USES_COMMENT)
         key_comment_total_bytes += 2 + key_info[i].comment.length;
