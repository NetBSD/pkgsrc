$NetBSD: patch-Library_System_TclTk_c__interface.c,v 1.1 2014/06/28 23:10:39 dholland Exp $

Fix build with tcl 8.6.

--- Library/System/TclTk/c_interface.c~	2007-07-01 03:53:35.000000000 +0000
+++ Library/System/TclTk/c_interface.c
@@ -33,11 +33,11 @@ void *ConstTclVolatile() {
 
 void delete_proc(ClientData client_data) {}
 
-int tkkit_cb_cmd(ClientData user_data, Tcl_Interp *tcl, int argc, char **argv) {
+int tkkit_cb_cmd(ClientData user_data, Tcl_Interp *tcl, int argc, const char **argv) {
   C_TCL_TK_tkkit_cb(argv);
 }
 
-int sather_cmd(ClientData user_data, Tcl_Interp *tcl, int argc, char **argv) {
+int sather_cmd(ClientData user_data, Tcl_Interp *tcl, int argc, const char **argv) {
   return C_TCL_TK_sather_cb((int) tcl, argv);
 }
 
@@ -66,7 +66,7 @@ char *str_ind(char **argv, int i) {
 }
 
 char *Tcl_GetResult(Tcl_Interp *interpreter) {
-  return interpreter->result;
+  return Tcl_GetStringResult(interpreter);
 }
 
 int Tk_AddRaster(Tcl_Interp *interp)
