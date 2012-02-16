$NetBSD: patch-src_portability.h,v 1.1 2012/02/16 18:36:34 hans Exp $

--- src/portability.h.orig	2001-09-02 21:57:36.000000000 +0200
+++ src/portability.h	2012-02-15 18:48:42.194632614 +0100
@@ -62,7 +62,7 @@ inline int unlink(const char* const file
 
 #elif defined __SVR4
 
-#include <cstdlib.h>
+#include <cstdlib>
 
 #endif	// _MSC_VER
 
