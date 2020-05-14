$NetBSD: patch-rlog-RLogChannel.cpp,v 1.2 2020/05/14 19:08:07 joerg Exp $

Fix strchr use.

--- rlog/RLogChannel.cpp.orig	2005-06-02 12:25:55.000000000 +0000
+++ rlog/RLogChannel.cpp
@@ -17,6 +17,7 @@
  */
 		                                                                                
 
+#include <cstring>
 #include "RLogChannel.h"
 #include "rlog.h"
 #include "Lock.h"
@@ -183,7 +184,7 @@ RLogChannel *rlog::GetComponentChannel( 
 	if((current->logLevel() == Log_Undef) && (level != Log_Undef))
 	    current->setLogLevel( level );
 
-	char *next = strchr( path , '/' );
+	const char *next = strchr( path , '/' );
 	size_t len = next ? next - path : strlen( path );
 
 	if(len > 1)
