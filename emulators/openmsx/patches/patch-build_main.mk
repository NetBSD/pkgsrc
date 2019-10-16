$NetBSD: patch-build_main.mk,v 1.1 2019/10/16 16:50:51 nia Exp $

Be less fussy about the name of the compiler executable.

--- build/main.mk.orig	2018-12-08 22:45:38.000000000 +0000
+++ build/main.mk
@@ -356,7 +356,6 @@ ifneq ($(filter %clang++,$(CXX))$(filter
   CC:=$(subst clang++,clang,$(CXX))
   DEPEND_FLAGS+=-MP
 else
-ifneq ($(filter %g++,$(CXX))$(filter g++%,$(CXX))$(findstring /g++-,$(CXX)),)
   # Generic compilation flags.
   COMPILE_FLAGS+=-pipe
   # Enable C++11
@@ -388,13 +387,6 @@ ifneq ($(filter %g++,$(CXX))$(filter g++
   DEPEND_FLAGS+=-MP
   # Plain C compiler, for the 3rd party libs.
   CC:=$(subst g++,gcc,$(CXX))
-else
-  ifneq ($(filter %gcc,$(CXX))$(filter gcc%,$(CXX)),)
-    $(error Set CXX to your "g++" executable instead of "gcc")
-  else
-    $(warning Unsupported compiler: $(CXX), please update Makefile)
-  endif
-endif
 endif
 
 # Strip binary?
