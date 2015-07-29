$NetBSD: patch-3rdparty_mongoose_mongoose.h,v 1.1 2015/07/29 12:03:40 wiz Exp $

Add missing header for va_list.

--- 3rdparty/mongoose/mongoose.h.orig	2015-07-29 06:34:21.000000000 +0000
+++ 3rdparty/mongoose/mongoose.h
@@ -20,6 +20,7 @@
 
 #define MONGOOSE_VERSION "5.6"
 
+#include <stdarg.h>     // required for va_list
 #include <stdio.h>      // required for FILE
 #include <stddef.h>     // required for size_t
 #include <sys/types.h>  // required for time_t
