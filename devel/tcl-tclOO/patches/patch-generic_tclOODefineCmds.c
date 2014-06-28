$NetBSD: patch-generic_tclOODefineCmds.c,v 1.1 2014/06/28 22:02:50 dholland Exp $

Fix build with tcl 8.6.

--- generic/tclOODefineCmds.c~	2013-09-18 09:35:24.000000000 +0000
+++ generic/tclOODefineCmds.c
@@ -775,7 +775,7 @@ GenerateErrorInfo(
     Tcl_AppendObjToErrorInfo(interp, Tcl_ObjPrintf(
 	    "\n    (in definition script for %s \"%.*s%s\" line %d)",
 	    typeOfSubject, (overflow ? limit : length), objName,
-	    (overflow ? "..." : ""), interp->errorLine));
+	    (overflow ? "..." : ""), Tcl_GetErrorLine(interp)));
 }
 
 /*
