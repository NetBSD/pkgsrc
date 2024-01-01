$NetBSD: patch-src_main_java_com_google_devtools_build_lib_analysis_config_AutoCpuConverter.java,v 1.1 2024/01/01 12:00:58 ryoon Exp $

--- src/main/java/com/google/devtools/build/lib/analysis/config/AutoCpuConverter.java.orig	2023-11-28 16:41:36.908346594 +0000
+++ src/main/java/com/google/devtools/build/lib/analysis/config/AutoCpuConverter.java
@@ -44,6 +44,8 @@ public class AutoCpuConverter extends Co
           }
         case FREEBSD:
           return "freebsd";
+        case NETBSD:
+          return "netbsd";
         case OPENBSD:
           return "openbsd";
         case WINDOWS:
@@ -98,6 +100,8 @@ public class AutoCpuConverter extends Co
       return Pair.of(CPU.getCurrent(), OS.DARWIN);
     } else if (input.startsWith("freebsd")) {
       return Pair.of(CPU.getCurrent(), OS.FREEBSD);
+    } else if (input.startsWith("netbsd")) {
+      return Pair.of(CPU.getCurrent(), OS.NETBSD);
     } else if (input.startsWith("openbsd")) {
       return Pair.of(CPU.getCurrent(), OS.OPENBSD);
     } else if (input.startsWith("x64_windows")) {
