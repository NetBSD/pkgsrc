$NetBSD: patch-hotspot_make_bsd_makefiles_rules.make,v 1.3 2015/02/09 00:42:17 tnn Exp $

--- hotspot/make/bsd/makefiles/rules.make.orig	2015-01-26 15:21:52.000000000 +0000
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
