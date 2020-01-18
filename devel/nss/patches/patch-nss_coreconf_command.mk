$NetBSD: patch-nss_coreconf_command.mk,v 1.3.30.1 2020/01/18 22:29:05 bsiegert Exp $

* Pass CFLAGS from pkgsrc

--- nss/coreconf/command.mk.orig	2019-12-04 00:03:31.000000000 +0000
+++ nss/coreconf/command.mk
@@ -12,7 +12,7 @@ AS            = $(CC)
 ASFLAGS      += $(CFLAGS)
 CCF           = $(CC) $(CFLAGS)
 LINK_DLL      = $(LD) $(OS_DLLFLAGS) $(DLLFLAGS) $(XLDFLAGS)
-CFLAGS        = $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
+CFLAGS       += $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
                 $(DEFINES) $(INCLUDES) $(XCFLAGS)
 CSTD          = -std=c99
 CXXSTD        = -std=c++11
