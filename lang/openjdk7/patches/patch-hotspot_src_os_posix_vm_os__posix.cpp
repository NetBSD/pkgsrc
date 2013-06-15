$NetBSD: patch-hotspot_src_os_posix_vm_os__posix.cpp,v 1.1 2013/06/15 09:31:05 jperkin Exp $

rlim_t fixes.

--- hotspot/src/os/posix/vm/os_posix.cpp.orig	2013-06-11 09:37:03.648327363 +0000
+++ hotspot/src/os/posix/vm/os_posix.cpp
@@ -130,12 +130,12 @@ void os::Posix::print_rlimit_info(output
 
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
 
   //Isn't there on solaris
@@ -148,7 +148,7 @@ void os::Posix::print_rlimit_info(output
 
   st->print(", NOFILE ");
   getrlimit(RLIMIT_NOFILE, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%d", rlim.rlim_cur);
 
 #ifdef __OpenBSD__
@@ -160,7 +160,7 @@ void os::Posix::print_rlimit_info(output
 #else
   st->print(", AS ");
   getrlimit(RLIMIT_AS, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%uk", rlim.rlim_cur >> 10);
   st->cr();
 #endif
