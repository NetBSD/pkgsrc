$NetBSD: patch-include_sasl.h,v 1.2 2013/09/30 06:24:09 obache Exp $

* #include <stddef.h> for size_t on NetBSD
  http://git.cyrusimap.org/cyrus-sasl/commit/?id=67a188693796a14e3a76ac603104807fbbfddfc4

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
