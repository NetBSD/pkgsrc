$NetBSD: patch-src_SimpleSaxHandler.h,v 1.1 2012/12/15 11:10:38 marino Exp $

Fix "clearPtrContainer" out of scope error on gcc4.6+

--- src/SimpleSaxHandler.h.orig	2009-10-13 12:02:58.000000000 +0000
+++ src/SimpleSaxHandler.h
@@ -101,7 +101,7 @@ struct SimpleSaxHandler : public QXmlDef
 
     /*override*/ ~SimpleSaxHandler()
     {
-        clearPtrContainer(m_lpNodes);
+        pearl::clearPtrContainer(m_lpNodes);
     }
 
 private:
