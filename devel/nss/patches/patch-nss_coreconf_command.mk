$NetBSD: patch-nss_coreconf_command.mk,v 1.3 2016/09/30 11:59:12 ryoon Exp $

* Pass CFLAGS from pkgsrc

--- nss/coreconf/command.mk.orig	2016-09-26 06:00:51.000000000 +0000
+++ nss/coreconf/command.mk
@@ -12,7 +12,7 @@ AS            = $(CC)
 ASFLAGS      += $(CFLAGS)
 CCF           = $(CC) $(CFLAGS)
 LINK_DLL      = $(LD) $(OS_DLLFLAGS) $(DLLFLAGS) $(XLDFLAGS)
-CFLAGS        = $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
+CFLAGS       += $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
                 $(DEFINES) $(INCLUDES) $(XCFLAGS)
 PERL          = perl
 RANLIB        = echo
