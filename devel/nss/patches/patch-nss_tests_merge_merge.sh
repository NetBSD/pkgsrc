$NetBSD: patch-nss_tests_merge_merge.sh,v 1.1 2018/02/24 11:35:48 ryoon Exp $

Revert Bug 1377940 to fix misc/libreoffice

--- nss/tests/merge/merge.sh.orig	2018-01-18 14:19:59.000000000 +0000
+++ nss/tests/merge/merge.sh
@@ -98,7 +98,7 @@ merge_init()
   # are dbm databases.
   if [ "${TEST_MODE}" = "UPGRADE_DB" ]; then
 	save=${NSS_DEFAULT_DB_TYPE}
-	NSS_DEFAULT_DB_TYPE=dbm ; export NSS_DEFAULT_DB_TYPE
+	NSS_DEFAULT_DB_TYPE= ; export NSS_DEFAULT_DB_TYPE
   fi
 
   certutil -N -d ${CONFLICT1DIR} -f ${R_PWFILE}
