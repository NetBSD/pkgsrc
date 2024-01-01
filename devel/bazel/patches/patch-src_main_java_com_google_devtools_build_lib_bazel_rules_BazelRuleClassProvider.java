$NetBSD: patch-src_main_java_com_google_devtools_build_lib_bazel_rules_BazelRuleClassProvider.java,v 1.1 2024/01/01 12:00:58 ryoon Exp $

--- src/main/java/com/google/devtools/build/lib/bazel/rules/BazelRuleClassProvider.java.orig	2023-11-30 05:47:44.632845320 +0000
+++ src/main/java/com/google/devtools/build/lib/bazel/rules/BazelRuleClassProvider.java
@@ -173,6 +173,7 @@ public class BazelRuleClassProvider {
       ImmutableMap.<OS, PathFragment>builder()
           .put(OS.WINDOWS, PathFragment.create("c:/tools/msys64/usr/bin/bash.exe"))
           .put(OS.FREEBSD, PathFragment.create("/usr/local/bin/bash"))
+          .put(OS.NETBSD, PathFragment.create("/usr/pkg/bin/bash"))
           .put(OS.OPENBSD, PathFragment.create("/usr/local/bin/bash"))
           .put(OS.UNKNOWN, FALLBACK_SHELL)
           .buildOrThrow();
