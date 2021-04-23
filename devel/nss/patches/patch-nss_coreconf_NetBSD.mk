$NetBSD: patch-nss_coreconf_NetBSD.mk,v 1.2 2021/04/23 16:07:43 rin Exp $

- fix wrong value of CPU_ARCH on NetBSD/evbarm-earmv7f
- s/aarch64eb/aarch64/

--- nss/coreconf/NetBSD.mk.orig	2021-04-16 01:17:44.000000000 +0900
+++ nss/coreconf/NetBSD.mk	2021-04-24 00:37:05.764452953 +0900
@@ -15,6 +15,12 @@
 OS_REL_CFLAGS		= -Di386
 CPU_ARCH		= x86
 endif
+ifeq (,$(filter-out earm%,$(CPU_ARCH)))
+CPU_ARCH		= arm
+endif
+ifeq ($(CPU_ARCH),aarch64eb)
+CPU_ARCH		= aarch64
+endif
 
 ifndef OBJECT_FMT
 OBJECT_FMT		:= $(shell if echo __ELF__ | $${CC:-cc} -E - | grep -q __ELF__ ; then echo a.out ; else echo ELF ; fi)
