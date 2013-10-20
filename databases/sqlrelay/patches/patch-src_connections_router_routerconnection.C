$NetBSD: patch-src_connections_router_routerconnection.C,v 1.1 2013/10/20 18:18:28 joerg Exp $

--- src/connections/router/routerconnection.C.orig	2013-10-17 12:22:33.000000000 +0000
+++ src/connections/router/routerconnection.C
@@ -600,8 +600,8 @@ void routercursor::checkForTempTable(con
 
 	// for oracle db's...
 
-	char	*ptr=(char *)query;
-	char	*endptr=(char *)query+length;
+	const char	*ptr=query;
+	const char	*endptr=query+length;
 
 	// skip any leading comments
 	if (!skipWhitespace(&ptr,endptr) || !skipComment(&ptr,endptr) ||
