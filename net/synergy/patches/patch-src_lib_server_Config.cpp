$NetBSD: patch-src_lib_server_Config.cpp,v 1.2 2021/06/25 09:49:24 tnn Exp $

Fix for some EOF problem. Not sure it's still required as the
previous patch has been adapted to upstream changes.

--- src/lib/server/Config.cpp.orig	2021-06-08 13:44:14.000000000 +0000
+++ src/lib/server/Config.cpp
@@ -1974,7 +1974,7 @@ ConfigReadContext::getLineNumber() const
 bool
 ConfigReadContext::operator!() const
 {
-	return !m_stream;
+	return m_stream.bad();
 }
 
 OptionValue
