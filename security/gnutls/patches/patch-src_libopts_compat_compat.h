$NetBSD: patch-src_libopts_compat_compat.h,v 1.3 2019/12/06 14:00:08 nia Exp $

Workaround for older OSX.

--- src/libopts/compat/compat.h.orig	2019-12-01 21:25:38.000000000 +0000
+++ src/libopts/compat/compat.h
@@ -182,7 +182,7 @@
 #  include <unistd.h>
 #endif
 
-#if defined(HAVE_STDBOOL_H)
+#if defined(HAVE_STDBOOL_H) || defined(__APPLE__)
 #  include <stdbool.h>
 #elif ! defined(bool)
    typedef enum { false = 0, true = 1 } _Bool;
