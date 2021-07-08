$NetBSD: patch-include_vigra_stdconvolution.hxx,v 1.1 2021/07/08 21:31:13 markd Exp $

fixed noexcept declaration
commit/dc730be49fc8def4304a651fa525e43b7754955e

--- include/vigra/stdconvolution.hxx.orig	2017-05-19 15:01:08.000000000 +0000
+++ include/vigra/stdconvolution.hxx
@@ -792,10 +792,10 @@ public:
         {}
 
         ~InitProxy()
-#ifndef _MSC_VER
-            throw(PreconditionViolation)
-#elif _MSC_VER >= 1900
+#if _MSC_VER >= 1900 || __cplusplus >= 201103L
             noexcept(false)
+#else
+	    throw(PreconditionViolation)
 #endif
         {
             vigra_precondition(count_ == 1 || count_ == sum_,
