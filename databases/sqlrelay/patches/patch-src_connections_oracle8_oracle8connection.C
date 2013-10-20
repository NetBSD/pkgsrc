$NetBSD: patch-src_connections_oracle8_oracle8connection.C,v 1.1 2013/10/20 18:18:28 joerg Exp $

--- src/connections/oracle8/oracle8connection.C.orig	2013-10-17 12:22:31.000000000 +0000
+++ src/connections/oracle8/oracle8connection.C
@@ -1076,8 +1076,8 @@ void oracle8cursor::returnOutputBindClob
 
 void oracle8cursor::checkForTempTable(const char *query, uint32_t length) {
 
-	char	*ptr=(char *)query;
-	char	*endptr=(char *)query+length;
+	const char	*ptr=query;
+	const char	*endptr=query+length;
 
 	// skip any leading comments
 	if (!skipWhitespace(&ptr,endptr) || !skipComment(&ptr,endptr) ||
