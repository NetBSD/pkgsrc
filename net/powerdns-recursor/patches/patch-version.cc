$NetBSD: patch-version.cc,v 1.1.2.2 2017/07/10 19:42:10 bsiegert Exp $

Don't include build time noise.

--- version.cc.orig	2017-07-03 00:20:50.928274609 +0000
+++ version.cc
@@ -108,13 +108,6 @@ void showBuildConfiguration()
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
