$NetBSD: patch-src_system_sysutils.h,v 1.1 2015/12/28 03:29:33 kamil Exp $

NetBSD ships with alloca() in <stdlib.h>

--- src/system/sysutils.h.orig	2012-10-28 10:30:09.000000000 +0000
+++ src/system/sysutils.h
@@ -40,7 +40,9 @@
 #ifdef __MINGW32__
 #include <malloc.h>
 #else
-#ifndef __MSVC__
+#ifdef __NetBSD__
+#include <stdlib.h>
+#elif !defined(__MSVC__)
 #include <alloca.h>
 #endif
 #endif
