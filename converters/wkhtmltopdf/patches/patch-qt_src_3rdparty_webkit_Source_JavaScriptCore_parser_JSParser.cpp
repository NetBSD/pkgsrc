$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_parser_JSParser.cpp,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/parser/JSParser.cpp.orig	2016-08-23 06:13:30.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/parser/JSParser.cpp
@@ -453,8 +453,8 @@ private:
         
         void copyCapturedVariablesToVector(const IdentifierSet& capturedVariables, Vector<RefPtr<StringImpl> >& vector)
         {
-            IdentifierSet::iterator end = capturedVariables.end();
-            for (IdentifierSet::iterator it = capturedVariables.begin(); it != end; ++it) {
+            IdentifierSet::const_iterator end = capturedVariables.end();
+            for (IdentifierSet::const_iterator it = capturedVariables.begin(); it != end; ++it) {
                 if (m_declaredVariables.contains(*it))
                     continue;
                 vector.append(*it);
