$NetBSD: patch-make_unix.mak,v 1.1 2011/12/04 21:59:37 marino Exp $

--- make/unix.mak.orig	2009-09-21 00:25:30.000000000 +0000
+++ make/unix.mak
@@ -57,7 +57,7 @@ release tagbuild
 .PHONY: all $(STANDARD_TARGETS)
 
 
-ifeq (,$(findstring $(OSTYPE),linux FreeBSD OpenBSD NetBSD solaris beos Darwin Carbon AIX Nucleus VxWorks rtems QNX cygwin mingw))
+ifeq (,$(findstring $(OSTYPE),linux DragonFly FreeBSD OpenBSD NetBSD solaris beos Darwin Carbon AIX Nucleus VxWorks rtems QNX cygwin mingw))
 
 default_target :
 	@echo
@@ -166,6 +166,31 @@ endif # linux
 
 ####################################################
 
+ifeq ($(OSTYPE),DragonFly)
+
+ifeq ($(MACHTYPE),x86)
+ifdef CPUTYPE
+STDCCFLAGS	+= -mcpu=$(CPUTYPE)
+endif
+endif
+
+ifeq ($(MACHTYPE),x86_64)
+STDCCFLAGS	+= -DP_64BIT
+endif
+
+P_USE_RANLIB	:= 1
+#STDCCFLAGS     += -DP_USE_PRAGMA		# migrated to configure
+
+ifeq ($(P_SHAREDLIB),1)
+ifndef PROG
+STDCCFLAGS	+= -fPIC -DPIC
+endif # PROG
+endif # P_SHAREDLIB
+
+endif # DragonFly
+
+####################################################
+
 ifeq ($(OSTYPE),FreeBSD)
 
 ifeq ($(MACHTYPE),x86)
