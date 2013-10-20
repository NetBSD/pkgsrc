$NetBSD: patch-src_connection_sqlrcursor_queryparse.C,v 1.1 2013/10/20 18:18:28 joerg Exp $

--- src/connection/sqlrcursor/queryparse.C.orig	2013-10-17 12:19:25.000000000 +0000
+++ src/connection/sqlrcursor/queryparse.C
@@ -49,8 +49,8 @@ char *sqlrcursor_svr::skipWhitespaceAndC
 
 void sqlrcursor_svr::checkForTempTable(const char *query, uint32_t length) {
 
-	char	*ptr=(char *)query;
-	char	*endptr=(char *)query+length;
+	const char	*ptr=query;
+	const char	*endptr=query+length;
 
 	// skip any leading comments
 	if (!skipWhitespace(&ptr,endptr) || !skipComment(&ptr,endptr) ||
@@ -78,7 +78,7 @@ void sqlrcursor_svr::checkForTempTable(c
 	conn->addSessionTempTableForDrop(tablename.getString());
 }
 
-bool sqlrcursor_svr::skipComment(char **ptr, const char *endptr) {
+bool sqlrcursor_svr::skipComment(const char **ptr, const char *endptr) {
 	while (*ptr<endptr && !charstring::compare(*ptr,"--",2)) {
 		while (**ptr && **ptr!='\n') {
 			(*ptr)++;
@@ -87,14 +87,14 @@ bool sqlrcursor_svr::skipComment(char **
 	return *ptr!=endptr;
 }
 
-bool sqlrcursor_svr::skipWhitespace(char **ptr, const char *endptr) {
+bool sqlrcursor_svr::skipWhitespace(const char **ptr, const char *endptr) {
 	while ((**ptr==' ' || **ptr=='\n' || **ptr=='	') && *ptr<endptr) {
 		(*ptr)++;
 	}
 	return *ptr!=endptr;
 }
 
-bool sqlrcursor_svr::advance(char **ptr, const char *endptr, uint16_t steps) {
+bool sqlrcursor_svr::advance(const char **ptr, const char *endptr, uint16_t steps) {
 	for (uint16_t i=0; i<steps && *ptr<endptr; i++) {
 		(*ptr)++;
 	}
