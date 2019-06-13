$NetBSD: patch-os__netbsd.cpp,v 1.5 2019/06/13 07:58:31 alnsn Exp $

Apply upstream commit r4919 to fix memory corruption.

--- os_netbsd.cpp.orig	2018-09-16 15:03:22.000000000 +0000
+++ os_netbsd.cpp
@@ -602,6 +602,12 @@ int netbsd_smart_interface::get_dev_name
     sprintf(mp[n], "%s%s%c", net_dev_raw_prefix, p, 'a' + getrawpartition());
     n++;
   }
+  free(disknames);
+
+  if (n == 0) {
+    free(mp);
+    return 0;
+  }
 
   char ** tmp = (char **)realloc(mp, n * (sizeof(char *)));
   if (NULL == tmp) {
