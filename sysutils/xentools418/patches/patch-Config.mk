$NetBSD: patch-Config.mk,v 1.2 2024/09/10 12:40:15 bouyer Exp $

Make sure to pass pkgsrc CFLAGS.
Use -R instead if -rpath, to appease our linker (--enable-rpath bug ?)

--- Config.mk.orig	2024-08-14 15:45:06.000000000 +0200
+++ Config.mk	2024-09-10 13:09:54.189244858 +0200
@@ -37,7 +37,7 @@
 
 # Tools to run on system hosting the build
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
-HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += -fno-strict-aliasing ${EXTRA_HOSTCFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
@@ -177,6 +177,8 @@
 
 CFLAGS += -Wall -Wstrict-prototypes
 
+CFLAGS += ${EXTRA_CFLAGS}
+
 $(call cc-option-add,CFLAGS,CC,-Wno-unused-but-set-variable)
 $(call cc-option-add,CFLAGS,CC,-Wno-unused-local-typedefs)
 
@@ -185,7 +187,7 @@
 LDFLAGS += $(foreach i, $(PREPEND_LIB), -L$(i))
 CFLAGS += $(foreach i, $(PREPEND_INCLUDES), -I$(i))
 ifeq ($(XEN_TOOLS_RPATH),y)
-LDFLAGS += -Wl,-rpath,$(libdir)
+LDFLAGS += -Wl,-R$(libdir)
 endif
 APPEND_LDFLAGS += $(foreach i, $(APPEND_LIB), -L$(i))
 APPEND_CFLAGS += $(foreach i, $(APPEND_INCLUDES), -I$(i))
