$NetBSD: patch-hotspot_make_bsd_makefiles_gcc.make,v 1.1 2015/02/21 20:21:56 tnn Exp $

Don't build with -O3 on ARM; produces flaky results with GCC 4.8.2.

--- hotspot/make/bsd/makefiles/gcc.make.orig	2015-01-26 15:21:52.000000000 +0000
+++ hotspot/make/bsd/makefiles/gcc.make
@@ -196,6 +196,8 @@ ifeq ($(OS_VENDOR), Darwin)
   # use -Os by default, unless -O3 can be proved to be worth the cost, as per policy
   # <http://wikis.sun.com/display/OpenJDK/Mac+OS+X+Port+Compilers>
   OPT_CFLAGS += -Os
+else ifeq ($(LIBARCH), arm)
+  OPT_CFLAGS += -Os
 else
   OPT_CFLAGS += -O3
 endif
