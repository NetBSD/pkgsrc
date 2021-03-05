$NetBSD: patch-enforcer_utils_1.4-2.0__db__convert_sqlite__convert.sql,v 1.1 2021/03/05 21:17:25 he Exp $

Fix bug in conversion script so that salt gets carried
over and not set to "0" in the target kasp.db, something
OpenDNSSEC will not recover from.

--- enforcer/utils/1.4-2.0_db_convert/sqlite_convert.sql.orig	2021-02-20 21:04:47.000000000 +0000
+++ enforcer/utils/1.4-2.0_db_convert/sqlite_convert.sql
@@ -222,7 +222,7 @@ SET denialSalt = (
 WHERE (
 	SELECT salt
 	FROM  REMOTE.policies
-	WHERE REMOTE.policies.id = policy.id) != null;
+	WHERE REMOTE.policies.id = policy.id) IS NOT NULL;
 
 UPDATE policy
 SET denialSaltLastChange = (
@@ -232,7 +232,7 @@ SET denialSaltLastChange = (
 WHERE (
 	SELECT salt_stamp
 	FROM  REMOTE.policies
-	WHERE REMOTE.policies.id = policy.id) != null;
+	WHERE REMOTE.policies.id = policy.id) IS NOT NULL;
 
 UPDATE policy
 SET keysTtl = (
