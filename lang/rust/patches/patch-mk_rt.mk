$NetBSD: patch-mk_rt.mk,v 1.2 2016/09/12 13:27:33 ryoon Exp $

Fix library location on SunOS.

--- mk/rt.mk.orig	2016-08-16 01:54:35.000000000 +0000
+++ mk/rt.mk
@@ -269,6 +269,16 @@ endif
 COMPRT_DEFINES_$(1) := -DCOMPILER_RT_ENABLE_IOS=ON
 endif
 
+ifeq ($$(findstring solaris,$(1)),solaris)
+COMPRT_DIR_$(1) := sunos
+COMPRT_LIB_NAME_$(1) := clang_rt.builtins-$$(COMPRT_ARCH_$(1))
+endif
+
+ifeq ($$(findstring netbsd,$(1)),netbsd)
+COMPRT_DIR_$(1) := netbsd
+COMPRT_LIB_NAME_$(1) := clang_rt.builtins-$$(COMPRT_ARCH_$(1))
+endif
+
 ifndef COMPRT_DIR_$(1)
 # NB: FreeBSD and NetBSD output to "linux"...
 COMPRT_DIR_$(1) := linux
