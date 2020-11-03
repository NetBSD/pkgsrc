$NetBSD: patch-m4_ax__lib__mysql.m4,v 1.1 2020/11/03 22:45:39 otis Exp $

Fix bash-ism.

--- m4/ax_lib_mysql.m4.orig	2020-08-24 09:42:55.000000000 +0000
+++ m4/ax_lib_mysql.m4
@@ -236,7 +236,7 @@ AC_DEFUN([AX_LIB_MYSQL],
             LDFLAGS="${LDFLAGS} ${MYSQL_LDFLAGS}"
             LIBS="${LIBS} ${MYSQL_LIBS}"
             LIBMYSQL_TLS_TRY_LINK([no])
-            if test "$found_mysql_tls" == "yes"; then
+            if test "$found_mysql_tls" = "yes"; then
                 LIBMYSQL_TLS_CIPHERS_TRY_LINK([no])
             else
                 LIBMARIADB_TLS_TRY_LINK([no])
