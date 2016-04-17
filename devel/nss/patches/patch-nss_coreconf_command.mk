$NetBSD: patch-nss_coreconf_command.mk,v 1.2 2016/04/17 19:27:10 ryoon Exp $

* Pass CFLAGS from pkgsrc

--- nss/coreconf/command.mk.orig	2016-02-26 20:51:11.000000000 +0000
+++ nss/coreconf/command.mk
@@ -12,7 +12,7 @@ AS            = $(CC)
 ASFLAGS      += $(CFLAGS)
 CCF           = $(CC) $(CFLAGS)
 LINK_DLL      = $(LINK) $(OS_DLLFLAGS) $(DLLFLAGS) $(XLDFLAGS)
-CFLAGS        = $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
+CFLAGS       += $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
                 $(DEFINES) $(INCLUDES) $(XCFLAGS)
 PERL          = perl
 RANLIB        = echo
