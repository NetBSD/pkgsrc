$NetBSD: patch-languages_cpp_cppcodecompletion.cpp,v 1.1 2012/06/25 11:21:35 joerg Exp $

--- languages/cpp/cppcodecompletion.cpp.orig	2012-06-18 23:10:55.000000000 +0000
+++ languages/cpp/cppcodecompletion.cpp
@@ -3892,15 +3892,15 @@ void CppCodeCompletion::computeCompletio
         ArgumentList fArgs = ( *it ) ->argumentList();
         if ( fArgs.count() != args.count() )
           continue;
-        ArgumentList::iterator it = args.begin();
+        ArgumentList::iterator ait = args.begin();
         ArgumentList::iterator it2 = fArgs.begin();
         bool hit = true;
-        while ( it != args.end() ) {
-          if ( ( *it ) ->type() != ( *it2 ) ->type() ) {
+        while ( ait != args.end() ) {
+          if ( ( *ait ) ->type() != ( *it2 ) ->type() ) {
             hit = false;
             break;
           }
-          ++it;
+          ++ait;
           ++it2;
         }
         if ( hit ) {
