$NetBSD: patch-clients_memflush.cc,v 1.2 2017/10/09 07:48:52 adam Exp $

Fix for missing definition of 'false'.

--- clients/memflush.cc.orig	2014-04-16 15:33:58.000000000 +0000
+++ clients/memflush.cc
@@ -39,7 +39,7 @@ int main(int argc, char *argv[])
 {
   options_parse(argc, argv);
 
-  if (opt_servers == false)
+  if (!opt_servers)
   {
     char *temp;
 
@@ -48,7 +48,7 @@ int main(int argc, char *argv[])
       opt_servers= strdup(temp);
     }
 
-    if (opt_servers == false)
+    if (!opt_servers)
     {
       std::cerr << "No Servers provided" << std::endl;
       exit(EXIT_FAILURE);
