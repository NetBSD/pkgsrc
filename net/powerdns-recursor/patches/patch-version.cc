$NetBSD: patch-version.cc,v 1.3 2025/06/30 11:06:46 jperkin Exp $

Do not store configure args, as they contain workdir references.

--- version.cc.orig	2025-06-23 11:49:15.710023097 +0000
+++ version.cc
@@ -155,7 +155,7 @@ void showBuildConfiguration()
   // Auth only
   g_log<<Logger::Warning<<"Built-in modules: "<<PDNS_MODULES<<endl;
 #endif
-#ifdef PDNS_CONFIG_ARGS
+#if 0
 #define double_escape(s) #s
 #define escape_quotes(s) double_escape(s)
   g_log<<Logger::Warning<<"Configured with: "<<escape_quotes(PDNS_CONFIG_ARGS)<<endl;
