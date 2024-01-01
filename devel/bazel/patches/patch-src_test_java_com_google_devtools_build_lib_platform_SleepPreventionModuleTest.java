$NetBSD: patch-src_test_java_com_google_devtools_build_lib_platform_SleepPreventionModuleTest.java,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/test/java/com/google/devtools/build/lib/platform/SleepPreventionModuleTest.java.orig	2023-11-30 05:51:43.180401312 +0000
+++ src/test/java/com/google/devtools/build/lib/platform/SleepPreventionModuleTest.java
@@ -32,6 +32,7 @@ public final class SleepPreventionModule
         return true;
       case LINUX:
       case FREEBSD:
+      case NETBSD:
       case OPENBSD:
       case UNKNOWN:
         return false;
