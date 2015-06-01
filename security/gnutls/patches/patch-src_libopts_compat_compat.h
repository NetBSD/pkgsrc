$NetBSD: patch-src_libopts_compat_compat.h,v 1.2 2015/06/01 21:50:22 spz Exp $

Workaround for older OSX.

--- src/libopts/compat/compat.h.orig	2015-03-23 07:19:23.000000000 +0000
+++ src/libopts/compat/compat.h
@@ -182,7 +182,7 @@
 #  include <unistd.h>
 #endif
 
-#ifdef HAVE_STDBOOL_H
+#if defined(HAVE_STDBOOL_H) || defined(__APPLE__)
 #  include <stdbool.h>
 #else
    typedef enum { false = 0, true = 1 } _Bool;
