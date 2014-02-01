$NetBSD: patch-tclcl.h,v 1.1 2014/02/01 08:00:06 markd Exp $

Build with tcl8.6

--- tclcl.h.orig	2005-09-07 04:53:51.000000000 +0000
+++ tclcl.h
@@ -85,7 +85,7 @@ class Tcl {
 	/* may not work at all! */
 	inline char* result() const { return (tcl_->result); }
 #endif  /* TCL_MAJOR_VERSION >= 8 */
-	inline void result(const char* p) { tcl_->result = (char*)p; }
+	inline void result(const char* p) { Tcl_SetResult (tcl_, (char *)p, NULL);}
 	void resultf(const char* fmt, ...);
 	inline void CreateCommand(const char* cmd, Tcl_CmdProc* cproc,
 				  ClientData cd = 0,
