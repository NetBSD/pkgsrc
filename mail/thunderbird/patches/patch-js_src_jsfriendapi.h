$NetBSD: patch-js_src_jsfriendapi.h,v 1.1 2020/09/03 15:26:22 ryoon Exp $

--- js/src/jsfriendapi.h.orig	2020-08-28 21:32:42.000000000 +0000
+++ js/src/jsfriendapi.h
@@ -14,6 +14,7 @@
 #include "mozilla/PodOperations.h"
 #include "mozilla/UniquePtr.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
