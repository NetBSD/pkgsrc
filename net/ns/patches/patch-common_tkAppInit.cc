$NetBSD: patch-common_tkAppInit.cc,v 1.1 2013/03/03 01:07:54 joerg Exp $

--- common/tkAppInit.cc.orig	2013-03-02 23:41:47.000000000 +0000
+++ common/tkAppInit.cc
@@ -31,7 +31,9 @@ extern EmbeddedTcl et_tk;
 /* MSVC requires this global var declaration to be outside of 'extern "C"' */
 #ifdef MEMDEBUG_SIMULATIONS
 #include "mem-trace.h"
+extern "C++" {
 MemTrace *globalMemTrace;
+}
 #endif
 
 #define NS_BEGIN_EXTERN_C	extern "C" {
@@ -293,7 +295,6 @@ int
 Tcl_AppInit(Tcl_Interp *interp)
 {
 #ifdef MEMDEBUG_SIMULATIONS
-        extern MemTrace *globalMemTrace;
         globalMemTrace = new MemTrace;
 #endif
 
