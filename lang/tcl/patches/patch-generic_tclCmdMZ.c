$NetBSD: patch-generic_tclCmdMZ.c,v 1.1 2011/08/16 10:18:58 cheusov Exp $

PR 45244
--- generic/tclCmdMZ.c.orig	2007-06-27 17:29:22.000000000 +0000
+++ generic/tclCmdMZ.c
@@ -3340,7 +3340,7 @@ TclTraceExecutionObjCmd(interp, optionIn
 		    flags |= (TCL_TRACE_ENTER_EXEC | 
 			      TCL_TRACE_LEAVE_EXEC);
 		}
-		strcpy(tcmdPtr->command, command);
+		memcpy(tcmdPtr->command, command, length + 1);
 		name = Tcl_GetString(objv[3]);
 		if (Tcl_TraceCommand(interp, name, flags, TraceCommandProc,
 			(ClientData) tcmdPtr) != TCL_OK) {
@@ -3572,7 +3572,7 @@ TclTraceCommandObjCmd(interp, optionInde
 		tcmdPtr->length = length;
 		tcmdPtr->refCount = 1;
 		flags |= TCL_TRACE_DELETE;
-		strcpy(tcmdPtr->command, command);
+		memcpy(tcmdPtr->command, command, length + 1);
 		name = Tcl_GetString(objv[3]);
 		if (Tcl_TraceCommand(interp, name, flags, TraceCommandProc,
 			(ClientData) tcmdPtr) != TCL_OK) {
@@ -3791,7 +3791,7 @@ TclTraceVariableObjCmd(interp, optionInd
 		}
 		tvarPtr->length = length;
 		flags |= TCL_TRACE_UNSETS | TCL_TRACE_RESULT_OBJECT;
-		strcpy(tvarPtr->command, command);
+		memcpy(tvarPtr->command, command, length + 1);
 		name = Tcl_GetString(objv[3]);
 		flagMask = TCL_GLOBAL_ONLY | TCL_NAMESPACE_ONLY;
 		varPtr = TclLookupVar(interp, name, NULL,
