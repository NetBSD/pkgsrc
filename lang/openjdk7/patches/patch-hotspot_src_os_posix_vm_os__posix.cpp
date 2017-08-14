$NetBSD: patch-hotspot_src_os_posix_vm_os__posix.cpp,v 1.2 2017/08/14 00:02:16 ryoon Exp $

rlim_t fixes.

--- hotspot/src/os/posix/vm/os_posix.cpp.orig	2017-08-13 05:55:27.000000000 +0000
+++ hotspot/src/os/posix/vm/os_posix.cpp
@@ -162,12 +162,12 @@ void os::Posix::print_rlimit_info(output
 
   st->print(" STACK ");
   getrlimit(RLIMIT_STACK, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%uk", rlim.rlim_cur >> 10);
 
   st->print(", CORE ");
   getrlimit(RLIMIT_CORE, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%uk", rlim.rlim_cur >> 10);
 
   // Isn't there on solaris and aix.
@@ -180,7 +180,7 @@ void os::Posix::print_rlimit_info(output
 
   st->print(", NOFILE ");
   getrlimit(RLIMIT_NOFILE, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%d", rlim.rlim_cur);
 
 #ifdef __OpenBSD__
@@ -192,7 +192,7 @@ void os::Posix::print_rlimit_info(output
 #else
   st->print(", AS ");
   getrlimit(RLIMIT_AS, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%uk", rlim.rlim_cur >> 10);
   st->cr();
 #endif
