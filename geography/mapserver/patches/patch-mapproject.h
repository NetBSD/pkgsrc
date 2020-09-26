$NetBSD: patch-mapproject.h,v 1.1 2020/09/26 12:21:57 mef Exp $

 #error 'To use the proj_api.h you must define the macro ACCEPT_USE_OF_DEPRECATED_PROJ_API_H'

--- mapproject.h.orig	2009-09-25 16:03:46.000000000 +0000
+++ mapproject.h
@@ -38,6 +38,7 @@ extern "C" {
 #endif
 
 #ifdef USE_PROJ
+#  define ACCEPT_USE_OF_DEPRECATED_PROJ_API_H 1
 #  include <proj_api.h>
 #endif
 
