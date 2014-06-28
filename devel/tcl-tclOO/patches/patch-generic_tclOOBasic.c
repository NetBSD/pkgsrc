$NetBSD: patch-generic_tclOOBasic.c,v 1.1 2014/06/28 22:02:50 dholland Exp $

Fix build with tcl 8.6.

--- generic/tclOOBasic.c~	2013-09-18 09:34:49.000000000 +0000
+++ generic/tclOOBasic.c
@@ -384,7 +384,7 @@ TclOO_Object_Eval(
     if (result == TCL_ERROR) {
 	Tcl_AppendObjToErrorInfo(interp, Tcl_ObjPrintf(
 		"\n    (in \"%s eval\" script line %d)",
-		TclGetString(objnameObj), interp->errorLine));
+		TclGetString(objnameObj), Tcl_GetErrorLine(interp)));
     }
 
     /*
