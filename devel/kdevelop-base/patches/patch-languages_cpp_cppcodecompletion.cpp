$NetBSD: patch-languages_cpp_cppcodecompletion.cpp,v 1.2 2013/05/04 12:59:46 joerg Exp $

--- languages/cpp/cppcodecompletion.cpp.orig	2009-02-26 20:15:14.000000000 +0000
+++ languages/cpp/cppcodecompletion.cpp
@@ -36,6 +36,7 @@ email                : david.nolden.kdev
 #include "tag_creator.h"
 
 #include <typeinfo>
+#include <vector>
 
 #include <qpopupmenu.h>
 
@@ -3892,15 +3893,15 @@ void CppCodeCompletion::computeCompletio
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
