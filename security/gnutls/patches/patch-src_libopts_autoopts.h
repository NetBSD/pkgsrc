$NetBSD: patch-src_libopts_autoopts.h,v 1.1 2014/08/30 12:45:11 adam Exp $

Avoid stdnoreturn.h.

--- src/libopts/autoopts.h.orig	2014-08-30 11:25:32.000000000 +0000
+++ src/libopts/autoopts.h
@@ -32,7 +32,6 @@
 
 #ifndef AUTOGEN_AUTOOPTS_H
 #define AUTOGEN_AUTOOPTS_H
-#include <stdnoreturn.h>
 
 #define AO_NAME_LIMIT           127
 #define AO_NAME_SIZE            ((size_t)(AO_NAME_LIMIT + 1))
