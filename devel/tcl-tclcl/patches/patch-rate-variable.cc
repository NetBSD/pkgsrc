$NetBSD: patch-rate-variable.cc,v 1.1 2014/02/01 08:00:06 markd Exp $

Build with tcl8.6

--- rate-variable.cc.orig	2005-09-07 04:53:51.000000000 +0000
+++ rate-variable.cc
@@ -65,7 +65,7 @@ void RateVariable::init()
 	(void)new RateVariable;
 }
 
-char* RateVariable::update_rate_var(ClientData clientData, Tcl_Interp* tcl,
+const char* RateVariable::update_rate_var(ClientData clientData, Tcl_Interp* tcl,
 				    CONST84 char* name1, 
 				    CONST84 char* name2, int flags)
 {
@@ -82,7 +82,7 @@ char* RateVariable::update_rate_var(Clie
 		flags &= TCL_GLOBAL_ONLY;
 		CONST char* cv = (char *) Tcl_GetVar2(tcl, name1, name2, flags);
 		if (cv == NULL)
-			return (tcl->result);
+			return (Tcl_GetStringResult(tcl));
 		int curval = atoi(cv);
 		double rate = 0.;
 		timeval tv;
