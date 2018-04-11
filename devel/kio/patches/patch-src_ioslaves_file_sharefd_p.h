$NetBSD: patch-src_ioslaves_file_sharefd_p.h,v 1.1 2018/04/11 11:50:35 markd Exp $

Deal with NetBSD sockaddr_un

--- src/ioslaves/file/sharefd_p.h.orig	2018-03-04 11:01:29.000000000 +0000
+++ src/ioslaves/file/sharefd_p.h
@@ -20,6 +20,7 @@
 
 #include <sys/un.h>
 #include <iostream>
+#include <string.h>
 #include <unistd.h>
 #include <sys/socket.h>
 
@@ -51,7 +52,11 @@ public:
 private:
     static sockaddr_un make_address(const std::string& path)
     {
-        sockaddr_un a{ AF_UNIX, {0}};
+        sockaddr_un a{
+#ifdef __NetBSD__
+            0,
+#endif
+	    AF_UNIX, {0}};
         std::string finalPath = "/tmp/" + path;
 #ifdef __linux__
         ::strcpy(&a.sun_path[1], finalPath.c_str());
