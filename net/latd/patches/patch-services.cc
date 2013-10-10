$NetBSD: patch-services.cc,v 1.1 2013/10/10 00:08:19 joerg Exp $

--- services.cc.orig	2013-10-09 22:51:37.000000000 +0000
+++ services.cc
@@ -257,14 +257,14 @@ void LATServices::serviceinfo::list_node
 
         output.setf(std::ios::hex, std::ios::basefield);
 
-        output << setiosflags(std::ios::right | std::ios::uppercase) << std::setfill('0')
+        output << std::setiosflags(std::ios::right | std::ios::uppercase) << std::setfill('0')
            << std::setw(2) << (int)addr[0] << '-'
            << std::setw(2) << (int)addr[1] << '-'
            << std::setw(2) << (int)addr[2] << '-'
            << std::setw(2) << (int)addr[3] << '-'
            << std::setw(2) << (int)addr[4] << '-'
            << std::setw(2) << (int)addr[5]
-           << resetiosflags(std::ios::right | std::ios::uppercase) << std::setfill(' ');
+           << std::resetiosflags(std::ios::right | std::ios::uppercase) << std::setfill(' ');
 
         output.setf(std::ios::right, std::ios::adjustfield);
         output << "  " << n->second.get_ident() <<  std::endl;
