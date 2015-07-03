$NetBSD: patch-hotspot_src_os_posix_vm_os__posix.cpp,v 1.3 2015/07/03 20:40:59 fhajny Exp $

rlim_t fixes.

--- hotspot/src/os/posix/vm/os_posix.cpp.orig	2015-06-10 10:31:52.000000000 +0000
+++ hotspot/src/os/posix/vm/os_posix.cpp
@@ -180,25 +180,25 @@ void os::Posix::print_rlimit_info(output
 
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
 #if !defined(TARGET_OS_FAMILY_solaris) && !defined(TARGET_OS_FAMILY_aix)
   st->print(", NPROC ");
   getrlimit(RLIMIT_NPROC, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%d", rlim.rlim_cur);
 #endif
 
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
