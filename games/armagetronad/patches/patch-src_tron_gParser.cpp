$NetBSD: patch-src_tron_gParser.cpp,v 1.1 2025/04/25 11:50:40 wiz Exp $

Fix build with libxml2 2.14.

--- src/tron/gParser.cpp.orig	2025-04-25 11:46:40.610636641 +0000
+++ src/tron/gParser.cpp
@@ -1120,8 +1120,10 @@ gParser::LoadAndValidateMapXML(char cons
 
 #ifndef DEDICATED
     /* reset error handler */
+#if 0
     initGenericErrorDefaultFunc( NULL );
 #endif
+#endif
 
     return validated;
 }
