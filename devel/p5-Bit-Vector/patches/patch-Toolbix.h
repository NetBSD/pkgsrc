$NetBSD: patch-Toolbix.h,v 1.1 2025/07/02 02:36:44 markd Exp $

fix build with C23
patch from Fedora 42


--- ToolBox.h.orig	2013-09-03 14:45:52.000000000 +0000
+++ ToolBox.h	2025-05-10 13:12:48.184554882 +0000
@@ -93,10 +93,19 @@ typedef  Z_longword         *Z_longwordp
     #elif PERL_DARWIN
         #define boolean bool
     #else
-	typedef int boolean;
-	#ifndef I_STDBOOL
-	    enum { false, true };
-	#endif
+        typedef int boolean;
+        #ifndef I_STDBOOL
+          #if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
+            #include <stdbool.h>
+          #else
+            #ifndef false
+              #define false 0
+            #endif
+            #ifndef true
+              #define true 1
+            #endif
+          #endif
+        #endif
     #endif
 #endif
 
