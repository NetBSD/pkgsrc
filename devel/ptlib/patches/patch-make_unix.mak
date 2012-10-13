$NetBSD: patch-make_unix.mak,v 1.2 2012/10/13 00:49:38 darcy Exp $

- Add DragonFly support

--- make/unix.mak.orig	2012-08-23 02:12:44.000000000 +0000
+++ make/unix.mak
@@ -57,7 +57,7 @@ release tagbuild
 .PHONY: all $(STANDARD_TARGETS)
 
 
-ifeq (,$(findstring $(OSTYPE),linux gnu FreeBSD OpenBSD NetBSD solaris beos Darwin Carbon AIX Nucleus VxWorks rtems QNX cygwin mingw))
+ifeq (,$(findstring $(OSTYPE),linux gnu DragonFly FreeBSD OpenBSD NetBSD solaris beos Darwin Carbon AIX Nucleus VxWorks rtems QNX cygwin mingw))
 
 default_target :
 	@echo
@@ -203,6 +203,31 @@ endif # gnu
 
 ####################################################
 
+ifeq ($(OSTYPE),DragonFly)
+
+ifeq ($(MACHTYPE),x86)
+ifdef CPUTYPE
+STDCCFLAGS += -mcpu=$(CPUTYPE)
+endif
+endif
+
+ifeq ($(MACHTYPE),x86_64)
+STDCCFLAGS += -DP_64BIT
+endif
+
+P_USE_RANLIB   := 1
+#STDCCFLAGS     += -DP_USE_PRAGMA      # migrated to configure
+
+ifeq ($(P_SHAREDLIB),1)
+ifndef PROG
+STDCCFLAGS += -fPIC -DPIC
+endif # PROG
+endif # P_SHAREDLIB
+
+endif # DragonFly
+
+####################################################
+
 ifeq ($(OSTYPE),FreeBSD)
 
 ifeq ($(MACHTYPE),x86)
