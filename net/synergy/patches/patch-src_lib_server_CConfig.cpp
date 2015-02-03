$NetBSD: patch-src_lib_server_CConfig.cpp,v 1.3 2015/02/03 18:49:34 tnn Exp $

Fix for some EOF problem. Not sure it's still required as the
previous patch has been adapted to upstream changes.

--- src/lib/server/Config.cpp.orig	2014-12-02 15:03:19.000000000 +0000
+++ src/lib/server/Config.cpp
@@ -1931,7 +1931,7 @@ ConfigReadContext::getLineNumber() const
 bool
 ConfigReadContext::operator!() const
 {
-	return !m_stream;
+	return m_stream.bad();
 }
 
 OptionValue
