$NetBSD: patch-gui_textconfig.cc,v 1.1 2024/02/11 23:30:39 ryoon Exp $

--- gui/textconfig.cc.orig	2021-03-27 17:23:31.183698000 +0000
+++ gui/textconfig.cc
@@ -45,6 +45,7 @@ extern "C" {
 #endif
 
 #include <stdio.h>
+#include <stdarg.h>
 #include <ctype.h>
 #include <string.h>
 #include <assert.h>
