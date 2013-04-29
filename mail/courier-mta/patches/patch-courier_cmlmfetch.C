$NetBSD: patch-courier_cmlmfetch.C,v 1.1 2013/04/29 21:22:17 joerg Exp $

--- courier/cmlmfetch.C.orig	2013-04-28 14:52:46.000000000 +0000
+++ courier/cmlmfetch.C
@@ -333,7 +333,7 @@ int doindex(const char *n)
 			ack << std::setiosflags(std::ios::right)
 			    << std::setw(10)
 			    << msgs[i]
-			    << resetiosflags(std::ios::right) << " "
+			    << std::resetiosflags(std::ios::right) << " "
 			    << std::setw(0) << msginfo[i].msgsubj << std::endl;
 			ack << std::setiosflags(std::ios::right)
 			    << std::setw(10)
