$NetBSD: patch-pgadmin_include_utils_pgDefs.h,v 1.1 2020/05/14 19:10:20 joerg Exp $

--- pgadmin/include/utils/pgDefs.h.orig	2020-05-09 23:47:34.954475346 +0000
+++ pgadmin/include/utils/pgDefs.h
@@ -18,9 +18,9 @@
 
 #define PGOID_CLASS_PG_AUTHID               1260L
 
-#define PGOID_TYPE_SERIAL                   -42L
-#define PGOID_TYPE_SERIAL8                  -43L
-#define PGOID_TYPE_SERIAL2                  -44L
+#define PGOID_TYPE_SERIAL                   ((OID)-42L)
+#define PGOID_TYPE_SERIAL8                  ((OID)-43L)
+#define PGOID_TYPE_SERIAL2                  ((OID)-44L)
 #define PGOID_TYPE_BOOL                     16L
 #define PGOID_TYPE_BYTEA                    17L
 #define PGOID_TYPE_CHAR                     18L
