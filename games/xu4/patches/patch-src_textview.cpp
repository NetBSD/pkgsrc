$NetBSD: patch-src_textview.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/textview.cpp.orig	2005-08-17 06:32:15.000000000 +0000
+++ src/textview.cpp
@@ -5,6 +5,7 @@
 #include "vc6.h" // Fixes things if you're using VC6, does nothing if otherwise
 
 #include <stdarg.h>
+#include <string.h>
 
 #include "debug.h"
 #include "event.h"
