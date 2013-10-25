$NetBSD: patch-src_libopts_compat_compat.h,v 1.1 2013/10/25 09:03:12 jperkin Exp $

Workaround for older OSX.

--- src/libopts/compat/compat.h.orig	2013-05-08 18:32:30.000000000 +0000
+++ src/libopts/compat/compat.h
@@ -182,7 +182,7 @@
 #  include <unistd.h>
 #endif
 
-#ifdef HAVE_STDBOOL_H
+#if defined(HAVE_STDBOOL_H) || defined(__APPLE__)
 #  include <stdbool.h>
 #else
    typedef enum { false = 0, true = 1 } _Bool;
