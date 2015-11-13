$NetBSD: patch-3rdparty_genie_build_gmake.solaris_genie.make,v 1.1 2015/11/13 14:11:49 wiz Exp $

Remove reference to non-existing file.
https://github.com/mamedev/mame/pull/464

--- 3rdparty/genie/build/gmake.solaris/genie.make.orig	2015-10-28 07:06:12.000000000 +0000
+++ 3rdparty/genie/build/gmake.solaris/genie.make
@@ -56,7 +56,6 @@ ifeq ($(config),release)
 	$(OBJDIR)/src/host/os_chdir.o \
 	$(OBJDIR)/src/host/os_copyfile.o \
 	$(OBJDIR)/src/host/os_getcwd.o \
-	$(OBJDIR)/src/host/os_getversion.o \
 	$(OBJDIR)/src/host/os_is64bit.o \
 	$(OBJDIR)/src/host/os_isdir.o \
 	$(OBJDIR)/src/host/os_isfile.o \
@@ -134,7 +133,6 @@ ifeq ($(config),debug)
 	$(OBJDIR)/src/host/os_chdir.o \
 	$(OBJDIR)/src/host/os_copyfile.o \
 	$(OBJDIR)/src/host/os_getcwd.o \
-	$(OBJDIR)/src/host/os_getversion.o \
 	$(OBJDIR)/src/host/os_is64bit.o \
 	$(OBJDIR)/src/host/os_isdir.o \
 	$(OBJDIR)/src/host/os_isfile.o \
@@ -252,10 +250,6 @@ $(OBJDIR)/src/host/os_getcwd.o: ../../sr
 	@echo $(notdir $<)
 	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF $(@:%.o=%.d) -c "$<"
 
-$(OBJDIR)/src/host/os_getversion.o: ../../src/host/os_getversion.c
-	@echo $(notdir $<)
-	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF $(@:%.o=%.d) -c "$<"
-
 $(OBJDIR)/src/host/os_is64bit.o: ../../src/host/os_is64bit.c
 	@echo $(notdir $<)
 	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF $(@:%.o=%.d) -c "$<"
