$NetBSD: patch-src_main_java_com_google_devtools_build_lib_runtime_CommonCommandOptions.java,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/main/java/com/google/devtools/build/lib/runtime/CommonCommandOptions.java.orig	2023-11-28 16:44:31.844523584 +0000
+++ src/main/java/com/google/devtools/build/lib/runtime/CommonCommandOptions.java
@@ -51,7 +51,7 @@ public class CommonCommandOptions extend
           "If true, Bazel picks up host-OS-specific config lines from bazelrc files. For example, "
               + "if the host OS is Linux and you run bazel build, Bazel picks up lines starting "
               + "with build:linux. Supported OS identifiers are linux, macos, windows, freebsd, "
-              + "and openbsd. Enabling this flag is equivalent to using --config=linux on Linux, "
+              + "netbsd and openbsd. Enabling this flag is equivalent to using --config=linux on Linux, "
               + "--config=windows on Windows, etc.")
   public boolean enablePlatformSpecificConfig;
 
