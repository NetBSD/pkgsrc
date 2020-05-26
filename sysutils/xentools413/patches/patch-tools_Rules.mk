$NetBSD: patch-tools_Rules.mk,v 1.1 2020/05/26 11:12:11 bouyer Exp $

--- tools/Rules.mk.orig	2019-12-17 15:23:09.000000000 +0100
+++ tools/Rules.mk	2020-05-08 16:55:13.142182769 +0200
@@ -102,54 +102,54 @@
 CFLAGS_libxentoollog = -I$(XEN_LIBXENTOOLLOG)/include $(CFLAGS_xeninclude)
 SHDEPS_libxentoollog =
 LDLIBS_libxentoollog = $(SHDEPS_libxentoollog) $(XEN_LIBXENTOOLLOG)/libxentoollog$(libextension)
-SHLIB_libxentoollog  = $(SHDEPS_libxentoollog) -Wl,-rpath-link=$(XEN_LIBXENTOOLLOG)
+SHLIB_libxentoollog  = $(SHDEPS_libxentoollog) -Wl,-rpath-link,$(XEN_LIBXENTOOLLOG)
 
 CFLAGS_libxentoolcore = -I$(XEN_LIBXENTOOLCORE)/include $(CFLAGS_xeninclude)
 SHDEPS_libxentoolcore =
 LDLIBS_libxentoolcore = $(SHDEPS_libxentoolcore) $(XEN_LIBXENTOOLCORE)/libxentoolcore$(libextension)
-SHLIB_libxentoolcore  = $(SHDEPS_libxentoolcore) -Wl,-rpath-link=$(XEN_LIBXENTOOLCORE)
+SHLIB_libxentoolcore  = $(SHDEPS_libxentoolcore) -Wl,-rpath-link,$(XEN_LIBXENTOOLCORE)
 
 CFLAGS_libxenevtchn = -I$(XEN_LIBXENEVTCHN)/include $(CFLAGS_xeninclude)
 SHDEPS_libxenevtchn = $(SHLIB_libxentoolcore)
 LDLIBS_libxenevtchn = $(SHDEPS_libxenevtchn) $(XEN_LIBXENEVTCHN)/libxenevtchn$(libextension)
-SHLIB_libxenevtchn  = $(SHDEPS_libxenevtchn) -Wl,-rpath-link=$(XEN_LIBXENEVTCHN)
+SHLIB_libxenevtchn  = $(SHDEPS_libxenevtchn) -Wl,-rpath-link,$(XEN_LIBXENEVTCHN)
 
 CFLAGS_libxengnttab = -I$(XEN_LIBXENGNTTAB)/include $(CFLAGS_xeninclude)
 SHDEPS_libxengnttab = $(SHLIB_libxentoollog) $(SHLIB_libxentoolcore)
 LDLIBS_libxengnttab = $(SHDEPS_libxengnttab) $(XEN_LIBXENGNTTAB)/libxengnttab$(libextension)
-SHLIB_libxengnttab  = $(SHDEPS_libxengnttab) -Wl,-rpath-link=$(XEN_LIBXENGNTTAB)
+SHLIB_libxengnttab  = $(SHDEPS_libxengnttab) -Wl,-rpath-link,$(XEN_LIBXENGNTTAB)
 
 CFLAGS_libxencall = -I$(XEN_LIBXENCALL)/include $(CFLAGS_xeninclude)
 SHDEPS_libxencall = $(SHLIB_libxentoolcore)
 LDLIBS_libxencall = $(SHDEPS_libxencall) $(XEN_LIBXENCALL)/libxencall$(libextension)
-SHLIB_libxencall  = $(SHDEPS_libxencall) -Wl,-rpath-link=$(XEN_LIBXENCALL)
+SHLIB_libxencall  = $(SHDEPS_libxencall) -Wl,-rpath-link,$(XEN_LIBXENCALL)
 
 CFLAGS_libxenforeignmemory = -I$(XEN_LIBXENFOREIGNMEMORY)/include $(CFLAGS_xeninclude)
 SHDEPS_libxenforeignmemory = $(SHLIB_libxentoolcore)
 LDLIBS_libxenforeignmemory = $(SHDEPS_libxenforeignmemory) $(XEN_LIBXENFOREIGNMEMORY)/libxenforeignmemory$(libextension)
-SHLIB_libxenforeignmemory  = $(SHDEPS_libxenforeignmemory) -Wl,-rpath-link=$(XEN_LIBXENFOREIGNMEMORY)
+SHLIB_libxenforeignmemory  = $(SHDEPS_libxenforeignmemory) -Wl,-rpath-link,$(XEN_LIBXENFOREIGNMEMORY)
 
 CFLAGS_libxendevicemodel = -I$(XEN_LIBXENDEVICEMODEL)/include $(CFLAGS_xeninclude)
 SHDEPS_libxendevicemodel = $(SHLIB_libxentoollog) $(SHLIB_libxentoolcore) $(SHLIB_xencall)
 LDLIBS_libxendevicemodel = $(SHDEPS_libxendevicemodel) $(XEN_LIBXENDEVICEMODEL)/libxendevicemodel$(libextension)
-SHLIB_libxendevicemodel  = $(SHDEPS_libxendevicemodel) -Wl,-rpath-link=$(XEN_LIBXENDEVICEMODEL)
+SHLIB_libxendevicemodel  = $(SHDEPS_libxendevicemodel) -Wl,-rpath-link,$(XEN_LIBXENDEVICEMODEL)
 
 # code which compiles against libxenctrl get __XEN_TOOLS__ and
 # therefore sees the unstable hypercall interfaces.
 CFLAGS_libxenctrl = -I$(XEN_LIBXC)/include $(CFLAGS_libxentoollog) $(CFLAGS_libxenforeignmemory) $(CFLAGS_libxendevicemodel) $(CFLAGS_xeninclude) -D__XEN_TOOLS__
 SHDEPS_libxenctrl = $(SHLIB_libxentoollog) $(SHLIB_libxenevtchn) $(SHLIB_libxengnttab) $(SHLIB_libxencall) $(SHLIB_libxenforeignmemory) $(SHLIB_libxendevicemodel)
 LDLIBS_libxenctrl = $(SHDEPS_libxenctrl) $(XEN_LIBXC)/libxenctrl$(libextension)
-SHLIB_libxenctrl  = $(SHDEPS_libxenctrl) -Wl,-rpath-link=$(XEN_LIBXC)
+SHLIB_libxenctrl  = $(SHDEPS_libxenctrl) -Wl,-rpath-link,$(XEN_LIBXC)
 
 CFLAGS_libxenguest = -I$(XEN_LIBXC)/include $(CFLAGS_libxenevtchn) $(CFLAGS_libxenforeignmemory) $(CFLAGS_xeninclude)
 SHDEPS_libxenguest = $(SHLIB_libxenevtchn)
 LDLIBS_libxenguest = $(SHDEPS_libxenguest) $(XEN_LIBXC)/libxenguest$(libextension)
-SHLIB_libxenguest  = $(SHDEPS_libxenguest) -Wl,-rpath-link=$(XEN_LIBXC)
+SHLIB_libxenguest  = $(SHDEPS_libxenguest) -Wl,-rpath-link,$(XEN_LIBXC)
 
 CFLAGS_libxenstore = -I$(XEN_XENSTORE)/include $(CFLAGS_xeninclude)
 SHDEPS_libxenstore = $(SHLIB_libxentoolcore)
 LDLIBS_libxenstore = $(SHDEPS_libxenstore) $(XEN_XENSTORE)/libxenstore$(libextension)
-SHLIB_libxenstore  = $(SHDEPS_libxenstore) -Wl,-rpath-link=$(XEN_XENSTORE)
+SHLIB_libxenstore  = $(SHDEPS_libxenstore) -Wl,-rpath-link,$(XEN_XENSTORE)
 ifeq ($(CONFIG_Linux),y)
 LDLIBS_libxenstore += -ldl
 endif
@@ -157,12 +157,12 @@
 CFLAGS_libxenstat  = -I$(XEN_LIBXENSTAT)
 SHDEPS_libxenstat  = $(SHLIB_libxenctrl) $(SHLIB_libxenstore)
 LDLIBS_libxenstat  = $(SHDEPS_libxenstat) $(XEN_LIBXENSTAT)/libxenstat$(libextension)
-SHLIB_libxenstat   = $(SHDEPS_libxenstat) -Wl,-rpath-link=$(XEN_LIBXENSTAT)
+SHLIB_libxenstat   = $(SHDEPS_libxenstat) -Wl,-rpath-link,$(XEN_LIBXENSTAT)
 
 CFLAGS_libxenvchan = -I$(XEN_LIBVCHAN)
 SHDEPS_libxenvchan = $(SHLIB_libxentoollog) $(SHLIB_libxenstore) $(SHLIB_libxenevtchn) $(SHLIB_libxengnttab)
 LDLIBS_libxenvchan = $(SHDEPS_libxenvchan) $(XEN_LIBVCHAN)/libxenvchan$(libextension)
-SHLIB_libxenvchan  = $(SHDEPS_libxenvchan) -Wl,-rpath-link=$(XEN_LIBVCHAN)
+SHLIB_libxenvchan  = $(SHDEPS_libxenvchan) -Wl,-rpath-link,$(XEN_LIBVCHAN)
 
 ifeq ($(debug),y)
 # Disable optimizations
@@ -176,12 +176,12 @@
 CFLAGS_libxenlight = -I$(XEN_XENLIGHT) $(CFLAGS_libxenctrl) $(CFLAGS_xeninclude)
 SHDEPS_libxenlight = $(SHLIB_libxenctrl) $(SHLIB_libxenstore)
 LDLIBS_libxenlight = $(SHDEPS_libxenlight) $(XEN_XENLIGHT)/libxenlight$(libextension)
-SHLIB_libxenlight  = $(SHDEPS_libxenlight) -Wl,-rpath-link=$(XEN_XENLIGHT)
+SHLIB_libxenlight  = $(SHDEPS_libxenlight) -Wl,-rpath-link,$(XEN_XENLIGHT)
 
 CFLAGS_libxlutil = -I$(XEN_XLUTIL)
 SHDEPS_libxlutil = $(SHLIB_libxenlight)
 LDLIBS_libxlutil = $(SHDEPS_libxlutil) $(XEN_XLUTIL)/libxlutil$(libextension)
-SHLIB_libxlutil  = $(SHDEPS_libxlutil) -Wl,-rpath-link=$(XEN_XLUTIL)
+SHLIB_libxlutil  = $(SHDEPS_libxlutil) -Wl,-rpath-link,$(XEN_XLUTIL)
 
 CFLAGS += -D__XEN_INTERFACE_VERSION__=__XEN_LATEST_INTERFACE_VERSION__
 
@@ -257,7 +257,7 @@
 	     -e 's!@@firmwaredir@@!$(XENFIRMWAREDIR)!g' \
 	     -e 's!@@libexecbin@@!$(LIBEXEC_BIN)!g' \
 	     -e 's!@@cflagslocal@@!$(PKG_CONFIG_CFLAGS_LOCAL)!g' \
-	     -e 's!@@libsflag@@\([^ ]*\)!-L\1 -Wl,-rpath-link=\1!g' \
+	     -e 's!@@libsflag@@\([^ ]*\)!-L\1 -Wl,-rpath-link,\1!g' \
 	     $(PKG_CONFIG_FILTER) < $< > $@
 
 %.pc: %.pc.in Makefile $(XEN_ROOT)/tools/Rules.mk
