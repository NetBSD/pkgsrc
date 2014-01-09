$NetBSD: patch-kviewshell_plugins_djvu_libdjvu_GSmartPointer.h,v 1.1 2014/01/09 20:11:27 jperkin Exp $

Include sys/types.h for size_t on SunOS

--- kviewshell/plugins/djvu/libdjvu/GSmartPointer.h.orig	2005-09-10 08:19:20.000000000 +0000
+++ kviewshell/plugins/djvu/libdjvu/GSmartPointer.h
@@ -99,6 +99,10 @@
 
 #include "DjVuGlobal.h"
 
+#ifdef __sun
+#include <sys/types.h>
+#endif
+
 #ifdef HAVE_NAMESPACES
 namespace DJVU {
 # ifdef NOT_DEFINED // Just to fool emacs c++ mode
