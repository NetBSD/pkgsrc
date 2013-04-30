$NetBSD: patch-src_CLucene_config_repl__tchar.h,v 1.1 2013/04/30 22:29:39 joerg Exp $

--- src/CLucene/config/repl_tchar.h.orig	2013-04-28 04:24:47.000000000 +0000
+++ src/CLucene/config/repl_tchar.h
@@ -33,7 +33,7 @@
     #define _tcscpy wcscpy //copy a string to another string
     #define _tcsncpy wcsncpy //copy a specified amount of one string to another string.
     #define _tcscat wcscat //copy a string onto the end of the other string
-    #define _tcschr wcschr //find location of one character
+    #define _tcschr ::std::wcschr //find location of one character
     #define _tcsstr wcsstr //find location of a string
     #define _tcslen wcslen //get length of a string
     #define _tcscmp wcscmp //case sensitive compare two strings
