$NetBSD: patch-nss_coreconf_command.mk,v 1.5 2026/11/19 02:49:18 wiz Exp $

* Pass CFLAGS from pkgsrc

--- nss/coreconf/command.mk.orig	2026-11-18 20:46:23.000000000 +0000
+++ nss/coreconf/command.mk
@@ -12,7 +12,7 @@ LINK_DLL      = $(LD) $(OS_DLLFLAGS) $(DLLFLAGS) $(XLD
 ASFLAGS      += $(CFLAGS)
 CCF           = $(CC) $(CFLAGS)
 LINK_DLL      = $(LD) $(OS_DLLFLAGS) $(DLLFLAGS) $(XLDFLAGS)
-CFLAGS        = $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
+CFLAGS       += $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
                 $(DEFINES) $(INCLUDES) $(XCFLAGS)
 CSTD          = -std=c99
 CXXSTD        = -std=c++17
