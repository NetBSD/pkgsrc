$NetBSD: patch-src_util_string-utf.cc,v 1.1 2011/11/25 22:11:44 joerg Exp $

--- src/util/string-utf.cc.orig	2011-11-25 18:45:16.000000000 +0000
+++ src/util/string-utf.cc
@@ -15,6 +15,7 @@
 #include <glib.h>
 #include <stdarg.h>
 #include <stdio.h>
+#include <string.h>
 
 #include <debug.hh>
 #include <string-utf.hh>
