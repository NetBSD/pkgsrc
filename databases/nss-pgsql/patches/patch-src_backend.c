# $NetBSD: patch-src_backend.c,v 1.1.1.1 2013/03/17 14:12:02 asau Exp $

Changes name of libpq-fe.h so it works on our PostgreSQL installation
Reorders list of copy_attr_colname as it references copy_attr_string

--- src/backend.c.orig	2008-08-19 09:44:37.000000000 +0000
+++ src/backend.c
@@ -11,7 +11,7 @@
  */
 
 #include "nss-pgsql.h"
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
@@ -205,22 +205,6 @@ inline void getent_close(char type)
   Assign a single value to *valptr from the specified row in the result
 */
 enum nss_status
-copy_attr_colnum(PGresult *res, int attrib_number, char **valptr,
-                 char **buffer, size_t *buflen, int *errnop, int row)
-{
-
-	const char *sptr;
-	size_t slen;
-
-	sptr = PQgetvalue(res, row, attrib_number);
-	return copy_attr_string(sptr, valptr, buffer, buflen, errnop);
-}
-
-/*
-  With apologies to nss_ldap...
-  Assign a single value to *valptr from the specified row in the result
-*/
-enum nss_status
 copy_attr_string(char *sptr, char **valptr,
                  char **buffer, size_t *buflen, int *errnop)
 {
@@ -244,6 +228,22 @@ copy_attr_string(char *sptr, char **valp
 }
 
 /*
+  With apologies to nss_ldap...
+  Assign a single value to *valptr from the specified row in the result
+*/
+enum nss_status
+copy_attr_colnum(PGresult *res, int attrib_number, char **valptr,
+                 char **buffer, size_t *buflen, int *errnop, int row)
+{
+
+	const char *sptr;
+	size_t slen;
+
+	sptr = PQgetvalue(res, row, attrib_number);
+	return copy_attr_string(sptr, valptr, buffer, buflen, errnop);
+}
+
+/*
  * return array of strings containing usernames that are member of group with gid 'gid'
  */
 enum nss_status getgroupmem(gid_t gid,
@@ -778,6 +778,7 @@ size_t backend_initgroups_dyn(const char
 	return *start;
 }
 
+#ifdef HAVE_SHADOW_H
 /*
  * 'convert' a PGresult to struct shadow
  */
@@ -863,4 +864,4 @@ enum nss_status backend_getspnam(const c
     
 	return status;
 }
-
+#endif
