$NetBSD: patch-js_src_jsfriendapi.h,v 1.1 2020/12/05 12:03:26 nia Exp $

Fix va_list error

--- js/src/jsfriendapi.h.orig	2020-11-04 10:51:54.000000000 +0000
+++ js/src/jsfriendapi.h
@@ -14,6 +14,7 @@
 #include "mozilla/PodOperations.h"
 #include "mozilla/UniquePtr.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
