$NetBSD: patch-hotspot_make_bsd_makefiles_buildtree.make,v 1.3 2015/02/09 00:42:17 tnn Exp $

--- hotspot/make/bsd/makefiles/buildtree.make.orig	2014-01-06 02:36:18.000000000 +0000
+++ hotspot/make/bsd/makefiles/buildtree.make
@@ -68,7 +68,7 @@ include $(GAMMADIR)/make/altsrc.make
 QUIETLY$(MAKE_VERBOSE)	= @
 
 # For now, until the compiler is less wobbly:
-TESTFLAGS	= -Xbatch -showversion
+TESTFLAGS	= -Xbatch -showversion $(PKGSRC_BOOT_JDK_JVMARGS)
 
 ifeq ($(findstring true, $(JVM_VARIANT_ZERO) $(JVM_VARIANT_ZEROSHARK)), true)
   PLATFORM_FILE = $(shell dirname $(shell dirname $(shell pwd)))/platform_zero
@@ -494,7 +494,7 @@ test_gamma:  $(BUILDTREE_MAKE) $(GAMMADI
 	echo "# Compile Queens program for test"; \
 	echo ""; \
 	echo "rm -f Queens.class"; \
-	echo "\$${JAVA_HOME}/bin/javac -d . $(GAMMADIR)/make/test/Queens.java"; \
+	echo "\$${JAVA_HOME}/bin/javac $(PKGSRC_BOOT_JDK_TOOLARGS) -d . $(GAMMADIR)/make/test/Queens.java"; \
 	echo ""; \
 	echo "# Set library path solely for gamma launcher test run"; \
 	echo ""; \
