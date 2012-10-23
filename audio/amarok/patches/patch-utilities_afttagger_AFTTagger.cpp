$NetBSD: patch-utilities_afttagger_AFTTagger.cpp,v 1.1 2012/10/23 10:32:44 markd Exp $

Use std::cin consistently to reference standard input

--- utilities/afttagger/AFTTagger.cpp.orig	2011-12-15 07:36:49.000000000 +0000
+++ utilities/afttagger/AFTTagger.cpp
@@ -88,7 +88,7 @@ AFTTagger::AFTTagger( int &argc, char **
         m_textStream.flush();
         std::string response;
         std::cin >> response;
-        cin.get();
+        std::cin.get();
 
         if( response != "y" && response != "Y")
         {
