--- src/AudioIO.cpp.orig	2006-11-15 05:12:10.000000000 +0100
+++ src/AudioIO.cpp	2012-01-15 19:16:58.001721823 +0100
@@ -25,6 +25,10 @@
 #include <math.h>
 #include <stdlib.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #ifdef __WXMSW__
 #include <malloc.h>
 #endif
