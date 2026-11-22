$NetBSD: patch-src_mobical.cpp,v 1.1 2026/11/22 12:10:51 drixter Exp $

Use POSIX feature detection instead of APPLE checks. 

--- /usr/work/amd64/wip/cadical3/work/cadical-rel-3.1.0/src/mobical.cpp.orig	2026-11-22 11:51:03.375061575 +0000
+++ /usr/work/amd64/wip/cadical3/work/cadical-rel-3.1.0/src/mobical.cpp
@@ -269,7 +269,7 @@ void initialize_allocators () {
   libc_realloc = reinterpret_cast<realloc_t> (dlsym (RTLD_NEXT, "realloc"));
   libc_free = reinterpret_cast<free_t> (dlsym (RTLD_NEXT, "free"));
 }
-#ifdef __APPLE__
+#ifdef _POSIX_VERSION
 __attribute__ ((section ("__DATA,__mod_init_func")))
 #else
 __attribute__ ((section (".preinit_array")))
@@ -7146,7 +7146,7 @@ void Trace::child_signal_handler (int si
 #endif
   struct rusage u;
   if (!getrusage (RUSAGE_SELF, &u)) {
-#ifndef __APPLE__
+#ifndef _POSIX_VERSION
     if ((int64_t) u.ru_maxrss >> 10 >= mobical.space_limit) {
 #else
     if ((int64_t) u.ru_maxrss >> 20 >= mobical.space_limit) {
@@ -7361,7 +7361,7 @@ int Trace::fork_and_execute () {
 
     // disable core dumps for faster delta-debugging.
 #ifndef _WIN32
-#ifdef __APPLE__
+#ifdef _POSIX_VERSION
     rlimit limit;
     limit.rlim_cur = 0;
     limit.rlim_max = 0;
