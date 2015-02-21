$NetBSD: patch-hotspot_make_bsd_makefiles_gcc.make,v 1.1 2015/02/21 20:21:56 tnn Exp $

Don't build with -O3 on ARM; produces flaky results with GCC 4.8.2.

--- hotspot/make/bsd/makefiles/gcc.make.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/make/bsd/makefiles/gcc.make
@@ -298,6 +298,8 @@ ifeq ($(OS_VENDOR), Darwin)
   # use -Os by default, unless -O3 can be proved to be worth the cost, as per policy
   # <http://wikis.sun.com/display/OpenJDK/Mac+OS+X+Port+Compilers>
   OPT_CFLAGS_DEFAULT ?= SIZE
+else ifeq ($(LIBARCH), arm)
+  OPT_CFLAGS_DEFAULT ?= SIZE
 else
   OPT_CFLAGS_DEFAULT ?= SPEED
 endif
