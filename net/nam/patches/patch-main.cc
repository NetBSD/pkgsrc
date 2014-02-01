$NetBSD: patch-main.cc,v 1.1 2014/02/01 08:07:01 markd Exp $

Fix build with tcl8.6

--- main.cc.orig	2011-11-04 17:18:42.000000000 +0000
+++ main.cc
@@ -222,7 +222,7 @@ extern "C" char version[];
 
 static int cmd_version(ClientData , Tcl_Interp* tcl, int , CONST84 char **)
 {
-	tcl->result = version;
+	Tcl_SetObjResult(tcl, Tcl_NewStringObj(version, -1));
 	return (TCL_OK);
 }
 
@@ -331,7 +331,7 @@ main(int argc, char **argv) {
 
 	Tcl_Interp *interp = Tcl_CreateInterp();
 	if (Tcl_Init(interp) == TCL_ERROR) {
-		printf("%s\n", interp->result);
+		printf("%s\n", Tcl_GetStringResult(interp));
 		abort();
 	}
 
@@ -350,7 +350,7 @@ main(int argc, char **argv) {
 #endif
 
 	if (Otcl_Init(interp) == TCL_ERROR) {
-		printf("%s\n", interp->result);
+		printf("%s\n", Tcl_GetStringResult(interp));
 		abort();
 	}
 #ifdef HAVE_LIBTCLDBG
@@ -372,7 +372,7 @@ main(int argc, char **argv) {
 	if (Tk_Init(tcl.interp()) == TCL_OK)
 		tk = Tk_MainWindow(tcl.interp());
 	if (tk == 0) {
-		fprintf(stderr, "nam: %s\n", interp->result);
+		fprintf(stderr, "nam: %s\n", Tcl_GetStringResult(interp));
 		exit(1);
 	}
 	tcl.tkmain(tk);
