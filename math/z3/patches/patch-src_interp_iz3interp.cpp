$NetBSD: patch-src_interp_iz3interp.cpp,v 1.1 2018/10/01 11:21:03 jperkin Exp $

rlim_t fixes.

--- src/interp/iz3interp.cpp.orig	2016-11-07 22:02:30.000000000 +0000
+++ src/interp/iz3interp.cpp
@@ -582,7 +582,7 @@ void interpolation_options_struct::apply
 class iz3stack_unlimiter {
 public:
     iz3stack_unlimiter() {
-        struct rlimit rl = {RLIM_INFINITY, RLIM_INFINITY};
+        struct rlimit rl = {(rlim_t)RLIM_INFINITY, (rlim_t)RLIM_INFINITY};
         setrlimit(RLIMIT_STACK, &rl);
         // nothing to be done if above fails
     }
