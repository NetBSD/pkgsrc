$NetBSD: patch-generic_tclOOInt.h,v 1.1 2014/06/28 22:02:50 dholland Exp $

Fix build with tcl 8.6.

--- generic/tclOOInt.h.orig	2013-08-03 11:47:14.000000000 +0000
+++ generic/tclOOInt.h
@@ -87,14 +87,14 @@ typedef struct ProcedureMethod {
     ClientData clientData;
     TclOO_PmCDDeleteProc *deleteClientdataProc;
     TclOO_PmCDCloneProc *cloneClientdataProc;
-    ProcErrorProc errProc;	/* Replacement error handler. */
+    ProcErrorProc *errProc;	/* Replacement error handler. */
     TclOO_PreCallProc *preCallProc;
 				/* Callback to allow for additional setup
 				 * before the method executes. */
     TclOO_PostCallProc *postCallProc;
 				/* Callback to allow for additional cleanup
 				 * after the method executes. */
-    GetFrameInfoValueProc gfivProc;
+    GetFrameInfoValueProc *gfivProc;
 				/* Callback to allow for fine tuning of how
 				 * the method reports itself. */
 } ProcedureMethod;
