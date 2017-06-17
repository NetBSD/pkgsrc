$NetBSD: patch-src_MainFormDlgImpl.cpp,v 1.1 2017/06/17 19:36:06 joerg Exp $

--- src/MainFormDlgImpl.cpp.orig	2017-06-10 15:47:07.854499376 +0000
+++ src/MainFormDlgImpl.cpp
@@ -119,7 +119,7 @@ namespace
         {
             m_strFileName = strFileName;
             ofstream_utf8 out (m_strFileName.c_str(), ios_base::app);
-            return out;
+            return bool(out);
         }
 
         void close() { m_strFileName.clear(); }
@@ -128,7 +128,7 @@ namespace
         {
             ofstream_utf8 out (m_strFileName.c_str(), ios_base::app);
             out << s;
-            return out;
+            return bool(out);
         }
     };
 #else // #ifndef WIN32
