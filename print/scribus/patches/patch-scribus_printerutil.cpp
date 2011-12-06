$NetBSD: patch-scribus_printerutil.cpp,v 1.1 2011/12/06 19:49:54 joerg Exp $

--- scribus/printerutil.cpp.orig	2011-12-06 14:37:43.000000000 +0000
+++ scribus/printerutil.cpp
@@ -9,6 +9,7 @@ for which a new license (GPL+exception) 
 
 #if defined( HAVE_CUPS )
  #include <cups/cups.h>
+ #include <cups/ppd.h>
 #elif defined(_WIN32)
  #include <windows.h>
  #include <winspool.h>
