$NetBSD: patch-nss_coreconf_Darwin.mk,v 1.3 2022/05/13 13:40:36 tnn Exp $

try to fix macOS/aarch64 to not detect as 32-bit

--- nss/coreconf/Darwin.mk.orig	2022-04-28 10:19:37.000000000 +0000
+++ nss/coreconf/Darwin.mk
@@ -16,6 +16,9 @@ ifndef CPU_ARCH
 # When cross-compiling, CPU_ARCH should already be defined as the target
 # architecture, set to powerpc or i386.
 CPU_ARCH	:= $(shell uname -p)
+  ifeq (arm64, $(shell uname -m))
+    override CPU_ARCH = aarch64
+  endif
 endif
 
 ifeq (,$(filter-out i%86,$(CPU_ARCH)))
@@ -33,11 +36,15 @@ else
 ifeq (arm,$(CPU_ARCH))
 # Nothing set for arm currently.
 else
+ifeq (aarch64,$(CPU_ARCH))
+# Nothing set for arm currently.
+else
 OS_REL_CFLAGS	= -Dppc
 CC              += -arch ppc
 CCC             += -arch ppc
 endif
 endif
+endif
 
 ifneq (,$(MACOS_SDK_DIR))
     GCC_VERSION_FULL := $(shell $(CC) -dumpversion)
