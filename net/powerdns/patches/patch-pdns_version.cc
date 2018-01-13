$NetBSD: patch-pdns_version.cc,v 1.1 2018/01/13 15:30:54 adam Exp $

Do not store configure arguments; they have references to the build directory.

--- pdns/version.cc.orig	2018-01-13 15:13:31.000000000 +0000
+++ pdns/version.cc
@@ -117,13 +117,6 @@ void showBuildConfiguration()
   // Auth only
   theL()<<Logger::Warning<<"Built-in modules: "<<PDNS_MODULES<<endl;
 #endif
-#ifdef PDNS_CONFIG_ARGS
-#define double_escape(s) #s
-#define escape_quotes(s) double_escape(s)
-  theL()<<Logger::Warning<<"Configured with: "<<escape_quotes(PDNS_CONFIG_ARGS)<<endl;
-#undef escape_quotes
-#undef double_escape
-#endif
 }
 
 string fullVersionString()
