$NetBSD: patch-version.cc,v 1.2 2020/03/17 19:07:29 adam Exp $

Do not store configure args, as they contain workdir references.

--- version.cc.orig	2020-03-17 17:04:42.000000000 +0000
+++ version.cc
@@ -145,7 +145,7 @@ void showBuildConfiguration()
   // Auth only
   g_log<<Logger::Warning<<"Built-in modules: "<<PDNS_MODULES<<endl;
 #endif
-#ifdef PDNS_CONFIG_ARGS
+#if 0
 #define double_escape(s) #s
 #define escape_quotes(s) double_escape(s)
   g_log<<Logger::Warning<<"Configured with: "<<escape_quotes(PDNS_CONFIG_ARGS)<<endl;
