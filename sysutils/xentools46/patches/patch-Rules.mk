$NetBSD: patch-Rules.mk,v 1.1.1.1 2016/07/04 07:30:50 jnemeth Exp $

--- Rules.mk.orig	2016-02-09 14:44:19.000000000 +0000
+++ Rules.mk
@@ -36,23 +36,23 @@ endif
 
 CFLAGS_libxenctrl = -I$(XEN_LIBXC)/include $(CFLAGS_xeninclude)
 LDLIBS_libxenctrl = $(XEN_LIBXC)/libxenctrl$(libextension)
-SHLIB_libxenctrl  = -Wl,-rpath-link=$(XEN_LIBXC)
+SHLIB_libxenctrl  = -Wl,-rpath-link,$(XEN_LIBXC)
 
 CFLAGS_libxenguest = -I$(XEN_LIBXC)/include $(CFLAGS_xeninclude)
 LDLIBS_libxenguest = $(XEN_LIBXC)/libxenguest$(libextension)
-SHLIB_libxenguest  = -Wl,-rpath-link=L$(XEN_LIBXC)
+SHLIB_libxenguest  = -Wl,-rpath-link,L$(XEN_LIBXC)
 
 CFLAGS_libxenstore = -I$(XEN_XENSTORE)/include $(CFLAGS_xeninclude)
 LDLIBS_libxenstore = $(XEN_XENSTORE)/libxenstore$(libextension)
-SHLIB_libxenstore  = -Wl,-rpath-link=$(XEN_XENSTORE)
+SHLIB_libxenstore  = -Wl,-rpath-link,$(XEN_XENSTORE)
 
 CFLAGS_libxenstat  = -I$(XEN_LIBXENSTAT)
 LDLIBS_libxenstat  = $(SHLIB_libxenctrl) $(SHLIB_libxenstore) $(XEN_LIBXENSTAT)/libxenstat$(libextension)
-SHLIB_libxenstat  = -Wl,-rpath-link=$(XEN_LIBXENSTAT)
+SHLIB_libxenstat  = -Wl,-rpath-link,$(XEN_LIBXENSTAT)
 
 CFLAGS_libxenvchan = -I$(XEN_LIBVCHAN)
 LDLIBS_libxenvchan = $(SHLIB_libxenctrl) $(SHLIB_libxenstore) $(XEN_LIBVCHAN)/libxenvchan$(libextension)
-SHLIB_libxenvchan  = -Wl,-rpath-link=$(XEN_LIBVCHAN)
+SHLIB_libxenvchan  = -Wl,-rpath-link,$(XEN_LIBVCHAN)
 
 ifeq ($(debug),y)
 # Disable optimizations and enable debugging information for macros
@@ -66,7 +66,7 @@ LIBXL_BLKTAP ?= $(CONFIG_BLKTAP2)
 ifeq ($(LIBXL_BLKTAP),y)
 CFLAGS_libblktapctl = -I$(XEN_BLKTAP2)/control -I$(XEN_BLKTAP2)/include $(CFLAGS_xeninclude)
 LDLIBS_libblktapctl = $(XEN_BLKTAP2)/control/libblktapctl$(libextension)
-SHLIB_libblktapctl  = -Wl,-rpath-link=$(XEN_BLKTAP2)/control
+SHLIB_libblktapctl  = -Wl,-rpath-link,$(XEN_BLKTAP2)/control
 else
 CFLAGS_libblktapctl =
 LDLIBS_libblktapctl =
@@ -75,7 +75,7 @@ endif
 
 CFLAGS_libxenlight = -I$(XEN_XENLIGHT) $(CFLAGS_libxenctrl) $(CFLAGS_xeninclude)
 LDLIBS_libxenlight = $(XEN_XENLIGHT)/libxenlight$(libextension) $(SHLIB_libxenctrl) $(SHLIB_libxenstore) $(SHLIB_libblktapctl)
-SHLIB_libxenlight  = -Wl,-rpath-link=$(XEN_XENLIGHT)
+SHLIB_libxenlight  = -Wl,-rpath-link,$(XEN_XENLIGHT)
 
 CFLAGS += -D__XEN_TOOLS__
 
