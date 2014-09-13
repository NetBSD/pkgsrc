$NetBSD: patch-hotspot_make_bsd_makefiles_rules.make,v 1.1 2014/09/13 14:35:25 joerg Exp $

--- hotspot/make/bsd/makefiles/rules.make.orig	2014-09-12 17:24:02.000000000 +0000
+++ hotspot/make/bsd/makefiles/rules.make
@@ -68,12 +68,12 @@ REMOVE_TARGET   = rm -f $@
 
 ifdef ALT_BOOTDIR
 
-RUN.JAVA  = $(ALT_BOOTDIR)/bin/java
-RUN.JAVAP = $(ALT_BOOTDIR)/bin/javap
-RUN.JAVAH = $(ALT_BOOTDIR)/bin/javah
-RUN.JAR   = $(ALT_BOOTDIR)/bin/jar
+RUN.JAVA  = $(ALT_BOOTDIR)/bin/java -XX:+UseSerialGC -mx1024m
+RUN.JAVAP = $(ALT_BOOTDIR)/bin/javap -J-XX:+UseSerialGC -J-mx1024m
+RUN.JAVAH = $(ALT_BOOTDIR)/bin/javah -J-XX:+UseSerialGC -J-mx1024m
+RUN.JAR   = $(ALT_BOOTDIR)/bin/jar -J-XX:+UseSerialGC -J-mx1024m
-COMPILE.JAVAC = $(ALT_BOOTDIR)/bin/javac
-COMPILE.RMIC = $(ALT_BOOTDIR)/bin/rmic
+COMPILE.JAVAC = $(ALT_BOOTDIR)/bin/javac -J-XX:+UseSerialGC -J-mx1024m
+COMPILE.RMIC = $(ALT_BOOTDIR)/bin/rmic -J-XX:+UseSerialGC -J-mx1024m
 BOOT_JAVA_HOME = $(ALT_BOOTDIR)
 
 else
