$NetBSD: patch-src_mumblemanager.cpp,v 1.1 2019/08/06 20:35:48 nia Exp $

Support NetBSD.

--- src/mumblemanager.cpp.orig	2019-01-26 18:51:56.000000000 +0000
+++ src/mumblemanager.cpp
@@ -16,9 +16,9 @@
 
 #include "utils/mathutils.h"
 
-#ifdef __OpenBSD__
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/param.h>
-#endif  // __OpenBSD__
+#endif
 #include <wchar.h>
 #include <cctype>
 
