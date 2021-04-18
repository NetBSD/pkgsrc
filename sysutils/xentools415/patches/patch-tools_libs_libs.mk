$NetBSD: patch-tools_libs_libs.mk,v 1.1 2021/04/18 12:31:26 bouyer Exp $

PKG_CONFIG is defined in environnement, rename to PKG_CONFIG_PC

--- tools/libs/libs.mk.orig	2021-04-06 19:14:18.000000000 +0200
+++ tools/libs/libs.mk	2021-04-17 13:40:31.365641659 +0200
@@ -1,7 +1,7 @@
 # Common Makefile for building a lib.
 #
 # Variables taken as input:
-#   PKG_CONFIG: name of pkg-config file (xen$(LIBNAME).pc if empty)
+#   PKG_CONFIG_PC: name of pkg-config file (xen$(LIBNAME).pc if empty)
 #   MAJOR:   major version of lib (Xen version if empty)
 #   MINOR:   minor version of lib (0 if empty)
 
@@ -29,7 +29,7 @@
 comma:= ,
 empty:=
 space:= $(empty) $(empty)
-PKG_CONFIG ?= $(LIB_FILE_NAME).pc
+PKG_CONFIG_PC ?= $(LIB_FILE_NAME).pc
 PKG_CONFIG_NAME ?= Xen$(LIBNAME)
 PKG_CONFIG_DESC ?= The $(PKG_CONFIG_NAME) library for Xen hypervisor
 PKG_CONFIG_VERSION := $(MAJOR).$(MINOR)
@@ -38,13 +38,13 @@
 PKG_CONFIG_REQPRIV := $(subst $(space),$(comma),$(strip $(foreach lib,$(patsubst ctrl,control,$(USELIBS_$(LIBNAME))),xen$(lib))))
 
 ifneq ($(CONFIG_LIBXC_MINIOS),y)
-PKG_CONFIG_INST := $(PKG_CONFIG)
+PKG_CONFIG_INST := $(PKG_CONFIG_PC)
 $(PKG_CONFIG_INST): PKG_CONFIG_PREFIX = $(prefix)
 $(PKG_CONFIG_INST): PKG_CONFIG_INCDIR = $(includedir)
 $(PKG_CONFIG_INST): PKG_CONFIG_LIBDIR = $(libdir)
 endif
 
-PKG_CONFIG_LOCAL := $(PKG_CONFIG_DIR)/$(PKG_CONFIG)
+PKG_CONFIG_LOCAL := $(PKG_CONFIG_DIR)/$(PKG_CONFIG_PC)
 
 LIBHEADER ?= $(LIB_FILE_NAME).h
 LIBHEADERS = $(foreach h, $(LIBHEADER), $(XEN_INCLUDE)/$(h))
@@ -112,7 +112,7 @@
 	$(SYMLINK_SHLIB) lib$(LIB_FILE_NAME).so.$(MAJOR).$(MINOR) $(DESTDIR)$(libdir)/lib$(LIB_FILE_NAME).so.$(MAJOR)
 	$(SYMLINK_SHLIB) lib$(LIB_FILE_NAME).so.$(MAJOR) $(DESTDIR)$(libdir)/lib$(LIB_FILE_NAME).so
 	for i in $(LIBHEADERS); do $(INSTALL_DATA) $$i $(DESTDIR)$(includedir); done
-	$(INSTALL_DATA) $(PKG_CONFIG) $(DESTDIR)$(PKG_INSTALLDIR)
+	$(INSTALL_DATA) $(PKG_CONFIG_PC) $(DESTDIR)$(PKG_INSTALLDIR)
 
 .PHONY: uninstall
 uninstall:
@@ -132,7 +132,7 @@
 	rm -rf *.rpm $(LIB) *~ $(DEPS_RM) $(LIB_OBJS) $(PIC_OBJS)
 	rm -f lib$(LIB_FILE_NAME).so.$(MAJOR).$(MINOR) lib$(LIB_FILE_NAME).so.$(MAJOR)
 	rm -f headers.chk headers.lst
-	rm -f $(PKG_CONFIG)
+	rm -f $(PKG_CONFIG_PC)
 	rm -f _paths.h
 
 .PHONY: distclean
