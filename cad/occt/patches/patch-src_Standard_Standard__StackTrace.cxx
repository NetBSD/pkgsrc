$NetBSD: patch-src_Standard_Standard__StackTrace.cxx,v 1.1 2023/02/12 14:42:25 tnn Exp $

Needs alloca.h on SunOS.
Fix build on NetBSD.

--- src/Standard/Standard_StackTrace.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/Standard/Standard_StackTrace.cxx
@@ -19,6 +19,10 @@
 
 #include <Standard_WarningDisableFunctionCast.hxx>
 
+#if defined(__sun)
+#include <alloca.h>
+#endif
+
 #if defined(__APPLE__)
   #import <TargetConditionals.h>
 #endif
@@ -200,7 +204,7 @@ Standard_Boolean Standard::StackTrace (c
   // theNbTraces is ignored
   // EM_LOG_JS_STACK?
   return emscripten_get_callstack (EM_LOG_C_STACK | EM_LOG_DEMANGLE | EM_LOG_NO_PATHS | EM_LOG_FUNC_PARAMS, theBuffer, theBufferSize) > 0;
-#elif defined(__ANDROID__)
+#elif defined(__ANDROID__) || defined(__NetBSD__)
   Message::SendTrace ("Standard::StackTrace() is not implemented for this platform");
   return false;
 #elif defined(__QNX__)
