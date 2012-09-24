$NetBSD: patch-src_lib_HTTP_HTTPParser.cpp,v 1.1 2012/09/24 10:29:36 ryoon Exp $

http://sourceforge.net/tracker/?func=detail&atid=751213&aid=3425300&group_id=141999

--- src/lib/HTTP/HTTPParser.cpp.orig	2009-12-20 20:26:29.000000000 +0000
+++ src/lib/HTTP/HTTPParser.cpp
@@ -52,7 +52,7 @@ bool CHTTPParser::parseHeader(std::strin
   else if(rxResponse.Search(header)) {
 		sType    = rxResponse.Match(2);
 		nVersion = atoi(rxResponse.Match(1).c_str());
-		message->m_sRequest = rxRequest.Match(3);
+		message->m_sRequest = rxResponse.Match(3);
 	}
 	else {    
 		return false;
