$NetBSD: patch-hotspot_make_bsd_makefiles_buildtree.make,v 1.1 2014/01/20 19:25:11 joerg Exp $

--- hotspot/make/bsd/makefiles/buildtree.make.orig	2014-01-06 02:36:18.000000000 +0000
+++ hotspot/make/bsd/makefiles/buildtree.make
@@ -68,7 +68,7 @@ include $(GAMMADIR)/make/altsrc.make
 QUIETLY$(MAKE_VERBOSE)	= @
 
 # For now, until the compiler is less wobbly:
-TESTFLAGS	= -Xbatch -showversion
+TESTFLAGS	= -Xbatch -showversion -Xmx512m -XX:+UseSerialGC
 
 ifeq ($(findstring true, $(JVM_VARIANT_ZERO) $(JVM_VARIANT_ZEROSHARK)), true)
   PLATFORM_FILE = $(shell dirname $(shell dirname $(shell pwd)))/platform_zero
