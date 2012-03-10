$NetBSD: patch-mozilla_ipc_chromium_chromium-config.mk,v 1.1 2012/03/10 11:42:39 ryoon Exp $

--- mozilla/ipc/chromium/chromium-config.mk.orig	2012-02-16 10:25:01.000000000 +0000
+++ mozilla/ipc/chromium/chromium-config.mk
@@ -56,17 +56,6 @@ LOCAL_INCLUDES += \
   -I$(DEPTH)/ipc/ipdl/_ipdlheaders \
   $(NULL)
 
-ifeq ($(OS_ARCH),Darwin) # {
-
-OS_MACOSX = 1
-OS_POSIX = 1
-
-DEFINES += \
-  -DOS_MACOSX=1 \
-  -DOS_POSIX=1 \
-  $(NULL)
-
-else # } {
 ifeq ($(OS_ARCH),WINNT) # {
 OS_LIBS += $(call EXPAND_LIBNAME,psapi shell32 dbghelp)
 
@@ -93,13 +82,62 @@ DEFINES += -DCOMPILER_MSVC
 endif
 
 else # } {
-
-OS_LINUX = 1
 OS_POSIX = 1
+DEFINES += -DOS_POSIX=1
+
+ifeq ($(OS_ARCH),Darwin) # {
+
+OS_MACOSX = 1
+DEFINES += \
+  -DOS_MACOSX=1 \
+  $(NULL)
+
+else # } {
+ifeq ($(OS_ARCH),DragonFly) # {
+
+OS_DRAGONFLY = 1
+OS_BSD = 1
+DEFINES += \
+  -DOS_DRAGONFLY=1 \
+  -DOS_BSD=1 \
+  $(NULL)
+
+else # } {
+ifeq ($(OS_ARCH),FreeBSD) # {
+
+OS_FREEBSD = 1
+OS_BSD = 1
+DEFINES += \
+  -DOS_FREEBSD=1 \
+  -DOS_BSD=1 \
+  $(NULL)
 
+else # } {
+ifeq ($(OS_ARCH),NetBSD) # {
+
+OS_NETBSD = 1
+OS_BSD = 1
+OS_LIBS += $(call EXPAND_LIBNAME,kvm)
+DEFINES += \
+  -DOS_NETBSD=1 \
+  -DOS_BSD=1 \
+  $(NULL)
+
+else # } {
+ifeq ($(OS_ARCH),OpenBSD) # {
+
+OS_OPENBSD = 1
+OS_BSD = 1
+DEFINES += \
+  -DOS_OPENBSD=1 \
+  -DOS_BSD=1 \
+  $(NULL)
+
+else # } {
+
+OS_LINUX = 1
 DEFINES += \
   -DOS_LINUX=1 \
-  -DOS_POSIX=1 \
   $(NULL)
 
 # NB: to stop gcc warnings about exporting template instantiation
@@ -107,4 +145,8 @@ OS_CXXFLAGS := $(filter-out -pedantic,$(
 
 endif # }
 endif # }
+endif # }
+endif # }
+endif # }
+endif # }
 
