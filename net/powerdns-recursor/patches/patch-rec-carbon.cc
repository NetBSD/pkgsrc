$NetBSD: patch-rec-carbon.cc,v 1.1 2020/06/17 22:55:11 otis Exp $

backport changes based on PR #9127 from
https://github.com/PowerDNS/pdns/pull/9127

--- rec-carbon.cc.orig	2020-06-17 21:27:18.582569489 +0000
+++ rec-carbon.cc
@@ -32,17 +32,13 @@ try
   if(namespace_name.empty()) {
     namespace_name="pdns";
   }
-  if(hostname.empty()) {
-    char tmp[HOST_NAME_MAX+1];
-    memset(tmp, 0, sizeof(tmp));
-    if (gethostname(tmp, sizeof(tmp)) != 0) {
-      throw std::runtime_error("The 'carbon-ourname' setting has not been set and we are unable to determine the system's hostname: " + stringerror());
+  if (hostname.empty()) {
+    try {
+      hostname = getCarbonHostName();
+    }
+    catch(const std::exception& e) {
+      throw std::runtime_error(std::string("The 'carbon-ourname' setting has not been set and we are unable to determine the system's hostname: ") + e.what());
     }
-    char *p = strchr(tmp, '.');
-    if(p) *p=0;
-
-    hostname=tmp;
-    boost::replace_all(hostname, ".", "_");    
   }
   if(instance_name.empty()) {
     instance_name="recursor";
