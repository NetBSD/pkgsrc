$NetBSD: patch-include_sasl.h,v 1.1 2012/12/20 22:52:37 joerg Exp $

--- include/sasl.h.orig	2012-12-20 22:26:09.000000000 +0000
+++ include/sasl.h
@@ -121,6 +121,8 @@
 #ifndef SASL_H
 #define SASL_H 1
 
+#include <stddef.h> /* For size_t */
+
 /* Keep in sync with win32/common.mak */
 #define SASL_VERSION_MAJOR 2
 #define SASL_VERSION_MINOR 1
