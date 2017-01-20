$NetBSD: patch-src_OpenGl_OpenGl__Context.hxx,v 1.1 2017/01/20 11:00:50 fhajny Exp $

We need alloca.h.

--- src/OpenGl/OpenGl_Context.hxx.orig	2017-01-13 05:34:36.000000000 +0000
+++ src/OpenGl/OpenGl_Context.hxx
@@ -40,6 +40,10 @@
 #include <OpenGl_GlCore11.hxx>
 #include <OpenGl_Utils.hxx>
 
+#if defined(__sun)
+#include <alloca.h>
+#endif
+
 //! Forward declarations
 #if defined(__APPLE__)
   #import <TargetConditionals.h>
