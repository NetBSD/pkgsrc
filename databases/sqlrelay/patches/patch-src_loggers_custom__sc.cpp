$NetBSD: patch-src_loggers_custom__sc.cpp,v 1.1 2014/05/27 09:55:04 joerg Exp $

--- src/loggers/custom_sc.cpp.orig	2014-05-23 17:02:08.000000000 +0000
+++ src/loggers/custom_sc.cpp
@@ -131,7 +131,7 @@ bool custom_sc::run(sqlrlistener *sqlrl,
 
 	// get the client IP, it's needed for some events
 	const char	*clientaddr="unknown";
-	if (sqlrcon && sqlrcon->cont->connstats->clientaddr) {
+	if (sqlrcon && sqlrcon->cont->connstats->clientaddr[0]) {
 		clientaddr=sqlrcon->cont->connstats->clientaddr;
 	}
 
