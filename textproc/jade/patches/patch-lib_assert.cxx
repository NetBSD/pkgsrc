$NetBSD: patch-lib_assert.cxx,v 1.1 2012/04/22 20:32:19 joerg Exp $

--- lib/assert.cxx.orig	2012-04-20 13:14:25.000000000 +0000
+++ lib/assert.cxx
@@ -5,10 +5,6 @@
 #include <stdlib.h>
 #include "macros.h"
 
-#ifdef __GNUG__
-void exit (int __status) throw () __attribute__ ((__noreturn__));
-#endif
-
 #ifdef SP_NAMESPACE
 namespace SP_NAMESPACE {
 #endif
