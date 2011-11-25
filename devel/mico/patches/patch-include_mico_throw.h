$NetBSD: patch-include_mico_throw.h,v 1.1 2011/11/25 21:46:29 joerg Exp $

--- include/mico/throw.h.orig	2011-11-25 19:47:33.000000000 +0000
+++ include/mico/throw.h
@@ -25,7 +25,7 @@
 #define __mico_throw_h__
 
 #include <stdarg.h>
-
+#include <string.h>
 
 #ifdef HAVE_EXCEPTIONS
 #define MICO_CATCHANY(x) try { x; } catch (...) {}
