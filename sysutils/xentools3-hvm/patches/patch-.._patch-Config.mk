$NetBSD: patch-.._patch-Config.mk,v 1.1 2013/04/11 19:57:52 joerg Exp $

--- ../Config.mk.orig	2011-12-07 10:40:48.000000000 +0000
+++ ../Config.mk
@@ -19,7 +19,7 @@ SHELL     ?= /bin/sh
 # Tools to run on system hosting the build
 HOSTCC      = gcc
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
-HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += -fno-strict-aliasing ${EXTRA_HOSTCFLAGS}
 HOSTCFLAGS_x86_32 = -m32
 HOSTCFLAGS_x86_64 = -m64
 HOSTCFLAGS += $(HOSTCFLAGS_$(XEN_COMPILE_ARCH))
@@ -70,10 +70,11 @@ CFLAGS += -Wall -Wstrict-prototypes
 
 # -Wunused-value makes GCC 4.x too aggressive for my taste: ignoring the
 # result of any casted expression causes a warning.
-CFLAGS += -Wno-unused-value
+CFLAGS += -Wno-unused-value -Wno-switch
 
 HOSTCFLAGS += $(call cc-option,$(HOSTCC),-Wdeclaration-after-statement,)
 CFLAGS     += $(call cc-option,$(CC),-Wdeclaration-after-statement,)
+CFLAGS += ${EXTRA_CFLAGS}
 
 LDFLAGS += $(foreach i, $(EXTRA_LIB), -L$(i)) 
 CFLAGS += $(foreach i, $(EXTRA_INCLUDES), -I$(i))
