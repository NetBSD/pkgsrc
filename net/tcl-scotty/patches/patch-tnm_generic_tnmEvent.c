$NetBSD: patch-tnm_generic_tnmEvent.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/generic/tnmEvent.c.orig	1996-08-27 20:24:58.000000000 +0000
+++ tnm/generic/tnmEvent.c
@@ -73,11 +73,11 @@ EventProc	_ANSI_ARGS_((ClientData client
 
 static int
 BindEvent	_ANSI_ARGS_((Tcl_Interp *interp, EventControl *control,
-			     int argc, char **argv));
+			     int argc, const char **argv));
 
 static int
 RaiseEvent	_ANSI_ARGS_((Tcl_Interp *interp, EventControl *control,
-			     int argc, char **argv));
+			     int argc, const char * const *argv));
 
 /*
  *----------------------------------------------------------------------
@@ -170,7 +170,7 @@ BindEvent(interp, control, argc, argv)
     Tcl_Interp *interp;
     EventControl *control;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_HashEntry *entryPtr;
 
@@ -249,7 +249,7 @@ RaiseEvent(interp, control, argc, argv)
     Tcl_Interp *interp;
     EventControl *control;
     int argc;
-    char **argv;
+    const char * const * argv;
 {
     Tcl_HashEntry *entryPtr;
 
@@ -299,7 +299,7 @@ Tnm_EventCmd(clientData, interp, argc, a
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     EventControl *control = (EventControl *) 
 	Tcl_GetAssocData(interp, tnmEventControl, NULL);
