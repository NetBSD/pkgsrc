$NetBSD: patch-gcc_vhdl_grt_Makefile.inc,v 1.1 2014/12/07 10:48:12 ryoon Exp $

--- gcc/vhdl/grt/Makefile.inc.orig	2014-12-07 04:08:50.000000000 +0000
+++ gcc/vhdl/grt/Makefile.inc
@@ -53,6 +53,14 @@ ifeq ($(filter-out x86_64 linux,$(arch) 
   GRT_TARGET_OBJS=amd64.o linux.o times.o
   GRT_EXTRA_LIB=-ldl -lm $(GRT_ELF_OPTS)
 endif
+ifeq ($(filter-out i%86 netbsd,$(arch) $(osys)),)
+  GRT_TARGET_OBJS=i386.o linux.o times.o
+  GRT_EXTRA_LIB=-lm $(GRT_ELF_OPTS)
+endif
+ifeq ($(filter-out x86_64 netbsd,$(arch) $(osys)),)
+  GRT_TARGET_OBJS=amd64.o linux.o times.o
+  GRT_EXTRA_LIB=-lm $(GRT_ELF_OPTS)
+endif
 ifeq ($(filter-out i%86 freebsd%,$(arch) $(osys)),)
   GRT_TARGET_OBJS=i386.o linux.o times.o
   GRT_EXTRA_LIB=-lm $(GRT_ELF_OPTS)
