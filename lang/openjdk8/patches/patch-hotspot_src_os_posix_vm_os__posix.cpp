$NetBSD: patch-hotspot_src_os_posix_vm_os__posix.cpp,v 1.1 2015/02/08 08:41:25 tnn Exp $

rlim_t fixes.

--- hotspot/src/os/posix/vm/os_posix.cpp.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/src/os/posix/vm/os_posix.cpp
@@ -160,12 +160,12 @@ void os::Posix::print_rlimit_info(output
 
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
@@ -178,12 +178,12 @@ void os::Posix::print_rlimit_info(output
 
   st->print(", NOFILE ");
   getrlimit(RLIMIT_NOFILE, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%d", rlim.rlim_cur);
 
   st->print(", AS ");
   getrlimit(RLIMIT_AS, &rlim);
-  if (rlim.rlim_cur == RLIM_INFINITY) st->print("infinity");
+  if (rlim.rlim_cur == (rlim_t)RLIM_INFINITY) st->print("infinity");
   else st->print("%uk", rlim.rlim_cur >> 10);
   st->cr();
 }
