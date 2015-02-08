$NetBSD: patch-hotspot_make_bsd_makefiles_rules.make,v 1.1 2015/02/08 08:41:25 tnn Exp $

--- hotspot/make/bsd/makefiles/rules.make.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/make/bsd/makefiles/rules.make
@@ -68,24 +68,24 @@ REMOVE_TARGET   = rm -f $@
 
 ifdef ALT_BOOTDIR
 
-RUN.JAVA  = $(ALT_BOOTDIR)/bin/java
-RUN.JAVAP = $(ALT_BOOTDIR)/bin/javap
-RUN.JAVAH = $(ALT_BOOTDIR)/bin/javah
-RUN.JAR   = $(ALT_BOOTDIR)/bin/jar
-COMPILE.JAVAC = $(ALT_BOOTDIR)/bin/javac
-COMPILE.RMIC = $(ALT_BOOTDIR)/bin/rmic
+RUN.JAVA  = $(ALT_BOOTDIR)/bin/java $(PKGSRC_BOOT_JDK_JVMARGS)
+RUN.JAVAP = $(ALT_BOOTDIR)/bin/javap $(PKGSRC_BOOT_JDK_TOOLARGS)
+RUN.JAVAH = $(ALT_BOOTDIR)/bin/javah $(PKGSRC_BOOT_JDK_TOOLARGS)
+RUN.JAR   = $(ALT_BOOTDIR)/bin/jar $(PKGSRC_BOOT_JDK_TOOLARGS)
+COMPILE.JAVAC = $(ALT_BOOTDIR)/bin/javac $(PKGSRC_BOOT_JDK_TOOLARGS)
+COMPILE.RMIC = $(ALT_BOOTDIR)/bin/rmic $(PKGSRC_BOOT_JDK_TOOLARGS)
 BOOT_JAVA_HOME = $(ALT_BOOTDIR)
 
 else
 
 ifdef BOOTDIR
 
-RUN.JAVA  = $(BOOTDIR)/bin/java
-RUN.JAVAP = $(BOOTDIR)/bin/javap
-RUN.JAVAH = $(BOOTDIR)/bin/javah
-RUN.JAR   = $(BOOTDIR)/bin/jar
-COMPILE.JAVAC = $(BOOTDIR)/bin/javac
-COMPILE.RMIC  = $(BOOTDIR)/bin/rmic
+RUN.JAVA  = $(BOOTDIR)/bin/java $(PKGSRC_BOOT_JDK_JVMARGS)
+RUN.JAVAP = $(BOOTDIR)/bin/javap $(PKGSRC_BOOT_JDK_TOOLARGS)
+RUN.JAVAH = $(BOOTDIR)/bin/javah $(PKGSRC_BOOT_JDK_TOOLARGS)
+RUN.JAR   = $(BOOTDIR)/bin/jar $(PKGSRC_BOOT_JDK_TOOLARGS)
+COMPILE.JAVAC = $(BOOTDIR)/bin/javac $(PKGSRC_BOOT_JDK_TOOLARGS)
+COMPILE.RMIC  = $(BOOTDIR)/bin/rmic $(PKGSRC_BOOT_JDK_TOOLARGS)
 BOOT_JAVA_HOME = $(BOOTDIR)
 
 else
@@ -129,7 +129,7 @@ RUN.JAR$(MAKE_VERBOSE) += >/dev/null
 BOOT_SOURCE_LANGUAGE_VERSION = 6
 BOOT_TARGET_CLASS_VERSION = 6
 JAVAC_FLAGS = -g -encoding ascii
-BOOTSTRAP_JAVAC_FLAGS = $(JAVAC_FLAGS) -source $(BOOT_SOURCE_LANGUAGE_VERSION) -target $(BOOT_TARGET_CLASS_VERSION)
+BOOTSTRAP_JAVAC_FLAGS = $(JAVAC_FLAGS) $(PKGSRC_BOOT_JDK_TOOLARGS) -source $(BOOT_SOURCE_LANGUAGE_VERSION) -target $(BOOT_TARGET_CLASS_VERSION)
 
 # With parallel makes, print a message at the end of compilation.
 ifeq    ($(findstring j,$(MFLAGS)),j)
