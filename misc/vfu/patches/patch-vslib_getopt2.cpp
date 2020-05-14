$NetBSD: patch-vslib_getopt2.cpp,v 1.2 2020/05/14 19:20:32 joerg Exp $

Sprinkle const to make more modern C++ compilers happier.

--- vslib/getopt2.cpp.orig	2001-10-28 13:53:02.000000000 +0000
+++ vslib/getopt2.cpp
@@ -40,7 +40,7 @@ static char *nextarg = NULL;
 
 /* Funktion */
 
-int getopt2(int argc, char *argv[], char *optstring)
+int getopt2(int argc, char *argv[], const char *optstring)
 
 /*
  *  AU: Auswertung der Kommandozeile
@@ -83,7 +83,7 @@ int getopt2(int argc, char *argv[], char
  */
 
 {
-    char *search;
+    const char *search;
 
     optarg = NULL;
 
