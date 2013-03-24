$NetBSD: patch-xsd-3.2.0-2_xsd_xsd.hxx,v 1.1 2013/03/24 16:58:29 joerg Exp $

--- xsd-3.2.0-2/xsd/xsd.hxx.orig	2013-03-23 19:57:50.000000000 +0000
+++ xsd-3.2.0-2/xsd/xsd.hxx
@@ -38,7 +38,7 @@ struct AutoUnlink
   {
     if (!canceled_)
     {
-      std::remove (file_.native_file_string ().c_str ());
+      std::remove (file_.string ().c_str ());
     }
   }
 
