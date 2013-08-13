$NetBSD: patch-src_shared_CLucene_config_repl__tchar.h,v 1.1 2013/08/13 10:24:22 joerg Exp $

--- src/shared/CLucene/config/repl_tchar.h.orig	2011-03-17 00:21:07.000000000 +0000
+++ src/shared/CLucene/config/repl_tchar.h
@@ -36,8 +36,8 @@
         #define _tcsncpy wcsncpy //copy a specified amount of one string to another string.
         #define _tcscat wcscat //copy a string onto the end of the other string
     		#define _tcsncat wcsncat
-        #define _tcschr wcschr //find location of one character
-        #define _tcsstr wcsstr //find location of a string
+        #define _tcschr ::std::wcschr //find location of one character
+        #define _tcsstr ::std::wcsstr //find location of a string
         #define _tcslen wcslen //get length of a string
         #define _tcscmp wcscmp //case sensitive compare two strings
         #define _tcsncmp wcsncmp //case sensitive compare two strings
