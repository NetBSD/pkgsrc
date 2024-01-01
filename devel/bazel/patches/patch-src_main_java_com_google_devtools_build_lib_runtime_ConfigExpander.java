$NetBSD: patch-src_main_java_com_google_devtools_build_lib_runtime_ConfigExpander.java,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/main/java/com/google/devtools/build/lib/runtime/ConfigExpander.java.orig	2023-11-28 16:45:00.372600192 +0000
+++ src/main/java/com/google/devtools/build/lib/runtime/ConfigExpander.java
@@ -48,6 +48,8 @@ final class ConfigExpander {
         return "windows";
       case FREEBSD:
         return "freebsd";
+      case NETBSD:
+        return "netbsd";
       case OPENBSD:
         return "openbsd";
       default:
