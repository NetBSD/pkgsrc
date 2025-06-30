$NetBSD: patch-pdns_version.cc,v 1.3 2025/06/30 11:00:50 jperkin Exp $

Do not store configure args, as they contain workdir references.

--- pdns/version.cc.orig	2025-05-07 09:29:28.000000000 +0000
+++ pdns/version.cc
@@ -160,7 +160,7 @@ void showBuildConfiguration()
   const auto& modules = BackendMakers().getModules();
   g_log << Logger::Warning << "Loaded modules: " << boost::join(modules, " ") << endl;
 #endif
-#ifdef PDNS_CONFIG_ARGS
+#if 0
 #define double_escape(s) #s
 #define escape_quotes(s) double_escape(s)
   g_log<<Logger::Warning<<"Configured with: "<<escape_quotes(PDNS_CONFIG_ARGS)<<endl;
