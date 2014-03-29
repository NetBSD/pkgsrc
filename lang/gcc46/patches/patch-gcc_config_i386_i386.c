$NetBSD: patch-gcc_config_i386_i386.c,v 1.1 2014/03/29 20:50:03 ryoon Exp $

* Fix PR pkg/48670.
  Fix build under NetBSD/i386 5.2 at least.
  From http://gitweb.dragonflybsd.org/dragonfly.git/commitdiff/5dd34005fbf5509736906dc6aa56d3e77f6a3dcb?hp=9d5dccab15766b547c37d9b452e0971d340a6453

--- gcc/config/i386/i386.c.orig	2013-04-02 16:54:58.000000000 +0000
+++ gcc/config/i386/i386.c
@@ -59,6 +59,9 @@ along with GCC; see the file COPYING3.  
 #include "sched-int.h"
 #include "sbitmap.h"
 #include "fibheap.h"
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
 
 enum upper_128bits_state
 {
@@ -32185,9 +32188,13 @@ ix86_mangle_type (const_tree type)
 static tree
 ix86_stack_protect_fail (void)
 {
+#if defined(__NetBSD__) && ( __NetBSD_Version__ >= 500000000) && ( __NetBSD_Version__ < 600000000)
+  return default_external_stack_protect_fail ();
+#else
   return TARGET_64BIT
 	 ? default_external_stack_protect_fail ()
 	 : default_hidden_stack_protect_fail ();
+#endif
 }
 
 /* Select a format to encode pointers in exception handling data.  CODE
