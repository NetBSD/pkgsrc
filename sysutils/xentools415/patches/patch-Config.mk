$NetBSD: patch-Config.mk,v 1.1 2021/04/18 12:31:26 bouyer Exp $

Make sure to pass pkgsrc CFLAGS.
Use -R instead if -rpath, to appease our linker (--enable-rpath bug ?)

--- Config.mk.orig	2020-12-08 15:28:31.000000000 +0100
+++ Config.mk	2020-12-14 11:48:10.669586105 +0100
@@ -33,7 +33,7 @@
 
 # Tools to run on system hosting the build
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
-HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += -fno-strict-aliasing ${EXTRA_HOSTCFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
@@ -188,6 +188,8 @@
 
 CFLAGS += -Wall -Wstrict-prototypes
 
+CFLAGS += ${EXTRA_CFLAGS}
+
 $(call cc-option-add,HOSTCFLAGS,HOSTCC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wno-unused-but-set-variable)
@@ -198,7 +200,7 @@
 LDFLAGS += $(foreach i, $(PREPEND_LIB), -L$(i))
 CFLAGS += $(foreach i, $(PREPEND_INCLUDES), -I$(i))
 ifeq ($(XEN_TOOLS_RPATH),y)
-LDFLAGS += -Wl,-rpath,$(libdir)
+LDFLAGS += -Wl,-R$(libdir)
 endif
 APPEND_LDFLAGS += $(foreach i, $(APPEND_LIB), -L$(i))
 APPEND_CFLAGS += $(foreach i, $(APPEND_INCLUDES), -I$(i))
