$NetBSD: patch-mozilla_js_src_frontend_ParseMaps.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/js/src/frontend/ParseMaps.cpp.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/js/src/frontend/ParseMaps.cpp
@@ -132,5 +132,5 @@ frontend::InitAtomMap(JSContext *cx, fro
     }
 }
 
-template class js::frontend::AtomDecls<FullParseHandler>;
-template class js::frontend::AtomDecls<SyntaxParseHandler>;
+template class frontend::AtomDecls<FullParseHandler>;
+template class frontend::AtomDecls<SyntaxParseHandler>;
