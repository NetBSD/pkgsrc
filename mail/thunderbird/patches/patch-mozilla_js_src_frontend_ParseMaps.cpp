$NetBSD: patch-mozilla_js_src_frontend_ParseMaps.cpp,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/js/src/frontend/ParseMaps.cpp.orig	2016-04-07 21:33:20.000000000 +0000
+++ mozilla/js/src/frontend/ParseMaps.cpp
@@ -133,5 +133,5 @@ frontend::InitAtomMap(frontend::AtomInde
     }
 }
 
-template class js::frontend::AtomDecls<FullParseHandler>;
-template class js::frontend::AtomDecls<SyntaxParseHandler>;
+template class frontend::AtomDecls<FullParseHandler>;
+template class frontend::AtomDecls<SyntaxParseHandler>;
