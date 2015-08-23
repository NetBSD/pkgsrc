$NetBSD: patch-Rules.mk,v 1.2 2015/08/23 16:17:12 spz Exp $

--- Rules.mk.orig	2014-09-02 06:22:57.000000000 +0000
+++ Rules.mk
@@ -21,23 +21,23 @@ CFLAGS_xeninclude = -I$(XEN_INCLUDE)
 
 CFLAGS_libxenctrl = -I$(XEN_LIBXC) $(CFLAGS_xeninclude)
 LDLIBS_libxenctrl = $(XEN_LIBXC)/libxenctrl.so
-SHLIB_libxenctrl  = -Wl,-rpath-link=$(XEN_LIBXC)
+SHLIB_libxenctrl  = -Wl,-rpath-link,$(XEN_LIBXC)
 
 CFLAGS_libxenguest = -I$(XEN_LIBXC) $(CFLAGS_xeninclude)
 LDLIBS_libxenguest = $(XEN_LIBXC)/libxenguest.so
-SHLIB_libxenguest  = -Wl,-rpath-link=L$(XEN_LIBXC)
+SHLIB_libxenguest  = -Wl,-rpath-link,$(XEN_LIBXC)
 
 CFLAGS_libxenstore = -I$(XEN_XENSTORE) $(CFLAGS_xeninclude)
 LDLIBS_libxenstore = $(XEN_XENSTORE)/libxenstore.so
-SHLIB_libxenstore  = -Wl,-rpath-link=$(XEN_XENSTORE)
+SHLIB_libxenstore  = -Wl,-rpath-link,$(XEN_XENSTORE)
 
 CFLAGS_libxenstat  = -I$(XEN_LIBXENSTAT)
 LDLIBS_libxenstat  = $(SHLIB_libxenctrl) $(SHLIB_libxenstore) $(XEN_LIBXENSTAT)/libxenstat.so
-SHLIB_libxenstat  = -Wl,-rpath-link=$(XEN_LIBXENSTAT)
+SHLIB_libxenstat  = -Wl,-rpath-link,$(XEN_LIBXENSTAT)
 
 CFLAGS_libxenvchan = -I$(XEN_LIBVCHAN)
 LDLIBS_libxenvchan = $(SHLIB_libxenctrl) $(SHLIB_libxenstore) -L$(XEN_LIBVCHAN) -lxenvchan
-SHLIB_libxenvchan  = -Wl,-rpath-link=$(XEN_LIBVCHAN)
+SHLIB_libxenvchan  = -Wl,-rpath-link,$(XEN_LIBVCHAN)
 
 ifeq ($(CONFIG_Linux),y)
 LIBXL_BLKTAP ?= y
@@ -48,7 +48,7 @@ endif
 ifeq ($(LIBXL_BLKTAP),y)
 CFLAGS_libblktapctl = -I$(XEN_BLKTAP2)/control -I$(XEN_BLKTAP2)/include $(CFLAGS_xeninclude)
 LDLIBS_libblktapctl = -L$(XEN_BLKTAP2)/control -lblktapctl
-SHLIB_libblktapctl  = -Wl,-rpath-link=$(XEN_BLKTAP2)/control
+SHLIB_libblktapctl  = -Wl,-rpath-link,$(XEN_BLKTAP2)/control
 else
 CFLAGS_libblktapctl =
 LDLIBS_libblktapctl =
@@ -57,7 +57,7 @@ endif
 
 CFLAGS_libxenlight = -I$(XEN_XENLIGHT) $(CFLAGS_libxenctrl) $(CFLAGS_xeninclude)
 LDLIBS_libxenlight = $(XEN_XENLIGHT)/libxenlight.so $(SHLIB_libxenctrl) $(SHLIB_libxenstore) $(SHLIB_libblktapctl)
-SHLIB_libxenlight  = -Wl,-rpath-link=$(XEN_XENLIGHT)
+SHLIB_libxenlight  = -Wl,-rpath-link,$(XEN_XENLIGHT)
 
 CFLAGS += -D__XEN_TOOLS__
 
