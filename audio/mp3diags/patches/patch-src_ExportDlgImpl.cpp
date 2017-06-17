$NetBSD: patch-src_ExportDlgImpl.cpp,v 1.1 2017/06/17 19:36:06 joerg Exp $

--- src/ExportDlgImpl.cpp.orig	2017-06-10 16:00:59.141430187 +0000
+++ src/ExportDlgImpl.cpp
@@ -371,7 +371,7 @@ bool ExportDlgImpl::exportAsText(const s
         out << "\n\n";
     }
 
-    return out;
+    return bool(out);
 }
 
 
@@ -424,7 +424,7 @@ bool ExportDlgImpl::exportAsM3u(const st
         out << pCodec->fromUnicode(qs).constData() << endl;
     }
 
-    return out;
+    return bool(out);
 }
 
 
@@ -761,6 +761,6 @@ bool ExportDlgImpl::exportAsXml(const st
 
     out << "</files>\n";
 
-    return out;
+    return bool(out);
 }
 
