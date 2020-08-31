$NetBSD: patch-gemrb_core_System_Logging.h,v 1.1 2020/08/31 12:46:21 nia Exp $

Include <cstdarg> for va_list

--- gemrb/core/System/Logging.h.orig	2020-08-23 18:32:26.000000000 +0000
+++ gemrb/core/System/Logging.h
@@ -29,6 +29,8 @@
 #include "exports.h"
 #include "win32def.h"
 
+#include <cstdarg>
+
 namespace GemRB {
 
 #ifdef WIN32
