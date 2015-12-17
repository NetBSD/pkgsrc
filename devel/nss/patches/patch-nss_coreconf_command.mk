$NetBSD: patch-nss_coreconf_command.mk,v 1.1 2015/12/17 13:39:59 ryoon Exp $

* Pass CFLAGS from pkgsrc

--- nss/coreconf/command.mk.orig	2015-11-09 05:12:59.000000000 +0000
+++ nss/coreconf/command.mk
@@ -12,7 +12,7 @@ AS            = $(CC)
 ASFLAGS      += $(CFLAGS)
 CCF           = $(CC) $(CFLAGS)
 LINK_DLL      = $(LINK) $(OS_DLLFLAGS) $(DLLFLAGS) $(XLDFLAGS)
-CFLAGS        = $(OPTIMIZER) $(OS_CFLAGS) $(XP_DEFINE) $(DEFINES) $(INCLUDES) \
+CFLAGS       += $(OPTIMIZER) $(OS_CFLAGS) $(XP_DEFINE) $(DEFINES) $(INCLUDES) \
 		$(XCFLAGS)
 PERL          = perl
 RANLIB        = echo
