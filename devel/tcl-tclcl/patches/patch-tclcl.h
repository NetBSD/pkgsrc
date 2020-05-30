$NetBSD: patch-tclcl.h,v 1.2 2020/05/30 20:43:40 joerg Exp $

Build with tcl8.6
Allow using C++11 compilers.

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
@@ -190,7 +190,7 @@ class TclObject {
 	/* give an error message and exit if the old variable 
 	   name is used either for read or write */
 #define _RENAMED(oldname, newname) \
-	bind_error(oldname, "variable "oldname" is renamed to "newname)
+	bind_error(oldname, "variable " oldname " is renamed to " newname)
 
 
 	virtual int init(int /*argc*/, const char*const* /*argv*/) {
