$NetBSD: patch-hotspot_src_os_posix_vm_os__posix.cpp,v 1.2 2015/06/10 11:38:51 tnn Exp $

rlim_t fixes.

--- hotspot/src/os/posix/vm/os_posix.cpp.orig	2015-06-09 13:49:55.000000000 +0000
+++ hotspot/src/os/posix/vm/os_posix.cpp
@@ -180,12 +180,12 @@ void os::Posix::print_rlimit_info(output
 
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
 
   // Isn't there on solaris
@@ -198,7 +198,7 @@ void os::Posix::print_rlimit_info(output
 
   st->print(", NOFILE ");
   getrlimit(RLIMIT_NOFILE, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%d", rlim.rlim_cur);
 
 #ifdef __OpenBSD__
@@ -208,7 +208,7 @@ void os::Posix::print_rlimit_info(output
   st->print(", AS ");
   getrlimit(RLIMIT_AS, &rlim);
 #endif
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%uk", rlim.rlim_cur >> 10);
   st->cr();
 }
