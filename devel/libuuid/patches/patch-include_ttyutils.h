$NetBSD: patch-include_ttyutils.h,v 1.3 2025/02/18 15:14:51 wiz Exp $

Fix build on systems that lack ECHOPRT.

--- include/ttyutils.h.orig	2025-02-18 15:11:47.748931987 +0000
+++ include/ttyutils.h
@@ -152,6 +152,9 @@ static inline void reset_virtual_console
 #ifndef FFDLY
 # define FFDLY 0
 #endif
+#ifndef ECHOPRT
+#define ECHOPRT 0
+#endif
 #ifndef TAB0
 # define TAB0 0
 #endif
