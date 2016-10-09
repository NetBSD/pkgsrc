$NetBSD: patch-lib_user_utilBacktrace.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/user/utilBacktrace.c.orig	2016-02-16 20:06:46.000000000 +0000
+++ lib/user/utilBacktrace.c
@@ -53,7 +53,7 @@
 #include "str.h"
 
 #ifdef VM_X86_64
-#   if defined(__GNUC__) && (!defined(USING_AUTOCONF) || defined(HAVE_UNWIND_H))
+#   if defined(__GNUC__) && (!defined(USING_AUTOCONF) || (defined(HAVE_UNWIND_H)) && !defined(__NetBSD__))
 #      define UTIL_BACKTRACE_USE_UNWIND
 #   endif
 #endif
