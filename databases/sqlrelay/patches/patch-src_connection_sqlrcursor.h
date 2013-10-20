$NetBSD: patch-src_connection_sqlrcursor.h,v 1.1 2013/10/20 18:18:28 joerg Exp $

--- src/connection/sqlrcursor.h.orig	2013-10-17 12:20:42.000000000 +0000
+++ src/connection/sqlrcursor.h
@@ -167,9 +167,9 @@ class sqlrcursor_svr {
 		// methods/variables used by derived classes
 		stringbuffer	*fakeInputBinds(const char *query);
 
-		bool	skipComment(char **ptr, const char *endptr);
-		bool	skipWhitespace(char **ptr, const char *endptr);
-		bool	advance(char **ptr, const char *endptr,
+		bool	skipComment(const char **ptr, const char *endptr);
+		bool	skipWhitespace(const char **ptr, const char *endptr);
+		bool	advance(const char **ptr, const char *endptr,
 						uint16_t steps);
 
 		sqlrconnection_svr	*conn;
