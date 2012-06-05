$NetBSD: patch-lingucomponent_source_languageguessing_simpleguesser.cxx,v 1.1 2012/06/05 21:53:42 wiz Exp $

Fixes a build issue: 'utfstrlen' was not declared in this scope
utfstrlen was never supposed to be used anyway:
http://www.mail-archive.com/libreoffice@lists.freedesktop.org/msg30469.html
--- lingucomponent/source/languageguessing/simpleguesser.cxx.orig	2012-05-22 12:48:18.000000000 +0000
+++ lingucomponent/source/languageguessing/simpleguesser.cxx
@@ -118,7 +118,7 @@ vector<Guess> SimpleGuesser::GuessLangua
         return guesses;
 
     //calculate le number of unicode charcters (symbols)
-    int len = utfstrlen(text);
+    int len = strlen(text);
 
     if (len > MAX_STRING_LENGTH_TO_ANALYSE)
         len = MAX_STRING_LENGTH_TO_ANALYSE;
