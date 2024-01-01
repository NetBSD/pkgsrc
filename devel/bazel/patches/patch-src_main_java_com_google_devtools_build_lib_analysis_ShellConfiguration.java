$NetBSD: patch-src_main_java_com_google_devtools_build_lib_analysis_ShellConfiguration.java,v 1.1 2024/01/01 12:00:58 ryoon Exp $

--- src/main/java/com/google/devtools/build/lib/analysis/ShellConfiguration.java.orig	2023-11-28 16:42:24.000271398 +0000
+++ src/main/java/com/google/devtools/build/lib/analysis/ShellConfiguration.java
@@ -84,6 +84,11 @@ public class ShellConfiguration extends 
                   OS_CONSTRAINT_SETTING,
                   Label.parseAbsoluteUnchecked("@platforms//os:freebsd")))
           .put(
+              OS.NETBSD,
+              ConstraintValueInfo.create(
+                  OS_CONSTRAINT_SETTING,
+                  Label.parseAbsoluteUnchecked("@platforms//os:netbsd")))
+          .put(
               OS.OPENBSD,
               ConstraintValueInfo.create(
                   OS_CONSTRAINT_SETTING,
