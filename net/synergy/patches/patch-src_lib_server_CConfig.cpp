$NetBSD: patch-src_lib_server_CConfig.cpp,v 1.2 2013/07/05 21:34:12 joerg Exp $

--- src/lib/server/CConfig.cpp.orig	2011-01-21 03:51:35.000000000 +0000
+++ src/lib/server/CConfig.cpp
@@ -1908,9 +1908,9 @@ CConfigReadContext::getLineNumber() cons
 	return m_line;
 }
 
-CConfigReadContext::operator void*() const
+CConfigReadContext::operator bool() const
 {
-	return m_stream;
+	return !m_stream.bad();
 }
 
 bool
