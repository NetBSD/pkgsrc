$NetBSD: patch-nss_coreconf_NetBSD.mk,v 1.1 2020/04/26 21:43:43 tnn Exp $

fix wrong value of CPU_ARCH on NetBSD/evbarm-earmv7f

--- nss/coreconf/NetBSD.mk.orig	2020-03-06 18:44:20.000000000 +0000
+++ nss/coreconf/NetBSD.mk
@@ -15,6 +15,9 @@ ifeq ($(CPU_ARCH),i386)
 OS_REL_CFLAGS		= -Di386
 CPU_ARCH		= x86
 endif
+ifeq (,$(filter-out earm%,$(CPU_ARCH)))
+CPU_ARCH		= arm
+endif
 
 ifndef OBJECT_FMT
 OBJECT_FMT		:= $(shell if echo __ELF__ | $${CC:-cc} -E - | grep -q __ELF__ ; then echo a.out ; else echo ELF ; fi)
