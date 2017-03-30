$NetBSD: patch-tools_Rules.mk,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/Rules.mk.orig	2016-12-05 13:03:27.000000000 +0100
+++ tools/Rules.mk	2017-03-24 17:48:17.000000000 +0100
@@ -84,57 +84,57 @@
 CFLAGS_libxentoollog = -I$(XEN_LIBXENTOOLLOG)/include $(CFLAGS_xeninclude)
 SHDEPS_libxentoollog =
 LDLIBS_libxentoollog = $(XEN_LIBXENTOOLLOG)/libxentoollog$(libextension)
-SHLIB_libxentoollog  = -Wl,-rpath-link=$(XEN_LIBXENTOOLLOG)
+SHLIB_libxentoollog  = -Wl,-rpath-link,$(XEN_LIBXENTOOLLOG)
 
 CFLAGS_libxenevtchn = -I$(XEN_LIBXENEVTCHN)/include $(CFLAGS_xeninclude)
 SHDEPS_libxenevtchn =
 LDLIBS_libxenevtchn = $(XEN_LIBXENEVTCHN)/libxenevtchn$(libextension)
-SHLIB_libxenevtchn  = -Wl,-rpath-link=$(XEN_LIBXENEVTCHN)
+SHLIB_libxenevtchn  = -Wl,-rpath-link,$(XEN_LIBXENEVTCHN)
 
 CFLAGS_libxengnttab = -I$(XEN_LIBXENGNTTAB)/include $(CFLAGS_xeninclude)
 SHDEPS_libxengnttab = $(SHLIB_libxentoollog)
 LDLIBS_libxengnttab = $(SHDEPS_libxengnttab) $(XEN_LIBXENGNTTAB)/libxengnttab$(libextension)
-SHLIB_libxengnttab  = $(SHDEPS_libxengnttab) -Wl,-rpath-link=$(XEN_LIBXENGNTTAB)
+SHLIB_libxengnttab  = $(SHDEPS_libxengnttab) -Wl,-rpath-link,$(XEN_LIBXENGNTTAB)
 
 # xengntshr_* interfaces are actually part of libxengnttab.so
 CFLAGS_libxengntshr = -I$(XEN_LIBXENGNTTAB)/include $(CFLAGS_xeninclude)
 LDLIBS_libxengntshr = $(XEN_LIBXENGNTTAB)/libxengnttab$(libextension)
-SHLIB_libxengntshr  = -Wl,-rpath-link=$(XEN_LIBXENGNTTAB)
+SHLIB_libxengntshr  = -Wl,-rpath-link,$(XEN_LIBXENGNTTAB)
 
 CFLAGS_libxencall = -I$(XEN_LIBXENCALL)/include $(CFLAGS_xeninclude)
 LDLIBS_libxencall = $(XEN_LIBXENCALL)/libxencall$(libextension)
-SHLIB_libxencall  = -Wl,-rpath-link=$(XEN_LIBXENCALL)
+SHLIB_libxencall  = -Wl,-rpath-link,$(XEN_LIBXENCALL)
 
 CFLAGS_libxenforeignmemory = -I$(XEN_LIBXENFOREIGNMEMORY)/include $(CFLAGS_xeninclude)
 LDLIBS_libxenforeignmemory = $(XEN_LIBXENFOREIGNMEMORY)/libxenforeignmemory$(libextension)
-SHLIB_libxenforeignmemory  = -Wl,-rpath-link=$(XEN_LIBXENFOREIGNMEMORY)
+SHLIB_libxenforeignmemory  = -Wl,-rpath-link,$(XEN_LIBXENFOREIGNMEMORY)
 
 # code which compiles against libxenctrl get __XEN_TOOLS__ and
 # therefore sees the unstable hypercall interfaces.
 CFLAGS_libxenctrl = -I$(XEN_LIBXC)/include $(CFLAGS_libxentoollog) $(CFLAGS_libxenforeignmemory) $(CFLAGS_xeninclude) -D__XEN_TOOLS__
 SHDEPS_libxenctrl = $(SHLIB_libxentoollog) $(SHLIB_libxenevtchn) $(SHLIB_libxengnttab) $(SHLIB_libxengntshr) $(SHLIB_libxencall) $(SHLIB_libxenforeignmemory)
 LDLIBS_libxenctrl = $(SHDEPS_libxenctrl) $(XEN_LIBXC)/libxenctrl$(libextension)
-SHLIB_libxenctrl  = $(SHDEPS_libxenctrl) -Wl,-rpath-link=$(XEN_LIBXC)
+SHLIB_libxenctrl  = $(SHDEPS_libxenctrl) -Wl,-rpath-link,$(XEN_LIBXC)
 
 CFLAGS_libxenguest = -I$(XEN_LIBXC)/include $(CFLAGS_libxenevtchn) $(CFLAGS_libxenforeignmemory) $(CFLAGS_xeninclude)
 SHDEPS_libxenguest = $(SHLIB_libxenevtchn)
 LDLIBS_libxenguest = $(SHDEPS_libxenguest) $(XEN_LIBXC)/libxenguest$(libextension)
-SHLIB_libxenguest  = $(SHDEPS_libxenguest) -Wl,-rpath-link=$(XEN_LIBXC)
+SHLIB_libxenguest  = $(SHDEPS_libxenguest) -Wl,-rpath-link,$(XEN_LIBXC)
 
 CFLAGS_libxenstore = -I$(XEN_XENSTORE)/include $(CFLAGS_xeninclude)
 SHDEPS_libxenstore =
 LDLIBS_libxenstore = $(SHDEPS_libxenguest) $(XEN_XENSTORE)/libxenstore$(libextension)
-SHLIB_libxenstore  = $(SHDEPS_libxenguest) -Wl,-rpath-link=$(XEN_XENSTORE)
+SHLIB_libxenstore  = $(SHDEPS_libxenguest) -Wl,-rpath-link,$(XEN_XENSTORE)
 
 CFLAGS_libxenstat  = -I$(XEN_LIBXENSTAT)
 SHDEPS_libxenstat  = $(SHLIB_libxenctrl) $(SHLIB_libxenstore)
 LDLIBS_libxenstat  = $(SHDEPS_libxenstat) $(XEN_LIBXENSTAT)/libxenstat$(libextension)
-SHLIB_libxenstat   = $(SHDEPS_libxenstat) -Wl,-rpath-link=$(XEN_LIBXENSTAT)
+SHLIB_libxenstat   = $(SHDEPS_libxenstat) -Wl,-rpath-link,$(XEN_LIBXENSTAT)
 
 CFLAGS_libxenvchan = -I$(XEN_LIBVCHAN)
 SHDEPS_libxenvchan = $(SHLIB_libxentoollog) $(SHLIB_libxenstore) $(SHLIB_libxenevtchn) $(SHLIB_libxengnttab) $(SHLIB_libxengntshr)
 LDLIBS_libxenvchan = $(SHDEPS_libxenvchan) $(XEN_LIBVCHAN)/libxenvchan$(libextension)
-SHLIB_libxenvchan  = $(SHDEPS_libxenvchan) -Wl,-rpath-link=$(XEN_LIBVCHAN)
+SHLIB_libxenvchan  = $(SHDEPS_libxenvchan) -Wl,-rpath-link,$(XEN_LIBVCHAN)
 
 ifeq ($(debug),y)
 # Disable optimizations and enable debugging information for macros
@@ -151,7 +151,7 @@
 CFLAGS_libblktapctl = -I$(XEN_BLKTAP2)/control -I$(XEN_BLKTAP2)/include $(CFLAGS_xeninclude)
 SHDEPS_libblktapctl =
 LDLIBS_libblktapctl = $(SHDEPS_libblktapctl) $(XEN_BLKTAP2)/control/libblktapctl$(libextension)
-SHLIB_libblktapctl  = $(SHDEPS_libblktapctl) -Wl,-rpath-link=$(XEN_BLKTAP2)/control
+SHLIB_libblktapctl  = $(SHDEPS_libblktapctl) -Wl,-rpath-link,$(XEN_BLKTAP2)/control
 else
 CFLAGS_libblktapctl =
 SHDEPS_libblktapctl =
@@ -162,7 +162,7 @@
 CFLAGS_libxenlight = -I$(XEN_XENLIGHT) $(CFLAGS_libxenctrl) $(CFLAGS_xeninclude)
 SHDEPS_libxenlight = $(SHLIB_libxenctrl) $(SHLIB_libxenstore) $(SHLIB_libblktapctl)
 LDLIBS_libxenlight = $(SHDEPS_libxenlight) $(XEN_XENLIGHT)/libxenlight$(libextension)
-SHLIB_libxenlight  = $(SHDEPS_libxenlight) -Wl,-rpath-link=$(XEN_XENLIGHT)
+SHLIB_libxenlight  = $(SHDEPS_libxenlight) -Wl,-rpath-link,$(XEN_XENLIGHT)
 
 CFLAGS += -D__XEN_INTERFACE_VERSION__=__XEN_LATEST_INTERFACE_VERSION__
 
