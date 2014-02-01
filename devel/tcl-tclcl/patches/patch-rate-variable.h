$NetBSD: patch-rate-variable.h,v 1.1 2014/02/01 08:00:06 markd Exp $

Build with tcl8.6

--- rate-variable.h.orig	2003-07-29 18:15:10.000000000 +0000
+++ rate-variable.h
@@ -41,7 +41,7 @@ public:
 	RateVariable() : TclCommand("rate_variable") {}
 	static void init();
 protected:
-	static char* update_rate_var(ClientData, Tcl_Interp*, 
+	static const char* update_rate_var(ClientData, Tcl_Interp*, 
 				     CONST84 char* name1,	
 				     CONST84 char* name2, 
 				     int flags);
