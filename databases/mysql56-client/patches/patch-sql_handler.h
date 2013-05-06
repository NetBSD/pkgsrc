$NetBSD: patch-sql_handler.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/handler.h.orig	2013-05-05 20:53:53.000000000 +0000
+++ sql/handler.h
@@ -3334,7 +3334,7 @@ static inline const char *ha_resolve_sto
 
 static inline bool ha_check_storage_engine_flag(const handlerton *db_type, uint32 flag)
 {
-  return db_type == NULL ? FALSE : test(db_type->flags & flag);
+  return db_type == NULL ? FALSE : my_test(db_type->flags & flag);
 }
 
 static inline bool ha_storage_engine_is_enabled(const handlerton *db_type)
