$NetBSD: patch-sql-common_client__authentication.cc,v 1.1 2018/02/05 16:09:52 jperkin Exp $

Backport upstream fix.

--- sql-common/client_authentication.cc.orig	2017-12-09 07:33:37.000000000 +0000
+++ sql-common/client_authentication.cc
@@ -84,7 +84,7 @@ RSA *rsa_init(MYSQL *mysql)
 
   if (mysql->options.extension != NULL &&
       mysql->options.extension->server_public_key_path != NULL &&
-      mysql->options.extension->server_public_key_path != '\0')
+      mysql->options.extension->server_public_key_path[0] != '\0')
   {
     pub_key_file= fopen(mysql->options.extension->server_public_key_path,
                         "r");
