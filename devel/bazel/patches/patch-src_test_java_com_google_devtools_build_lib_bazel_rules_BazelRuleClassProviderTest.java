$NetBSD: patch-src_test_java_com_google_devtools_build_lib_bazel_rules_BazelRuleClassProviderTest.java,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/test/java/com/google/devtools/build/lib/bazel/rules/BazelRuleClassProviderTest.java.orig	2023-11-30 05:50:35.115838020 +0000
+++ src/test/java/com/google/devtools/build/lib/bazel/rules/BazelRuleClassProviderTest.java
@@ -218,6 +218,8 @@ public class BazelRuleClassProviderTest 
         .isEqualTo(PathFragment.create("/bin/bash"));
     assertThat(determineShellExecutable(OS.FREEBSD, null))
         .isEqualTo(PathFragment.create("/usr/local/bin/bash"));
+    assertThat(determineShellExecutable(OS.NETBSD, null))
+        .isEqualTo(PathFragment.create("/usr/pkg/bin/bash"));
     assertThat(determineShellExecutable(OS.OPENBSD, null))
         .isEqualTo(PathFragment.create("/usr/local/bin/bash"));
     assertThat(determineShellExecutable(OS.WINDOWS, null))
@@ -231,6 +233,8 @@ public class BazelRuleClassProviderTest 
         .isEqualTo(PathFragment.create("/bin/bash"));
     assertThat(determineShellExecutable(OS.FREEBSD, binBash))
         .isEqualTo(PathFragment.create("/bin/bash"));
+    assertThat(determineShellExecutable(OS.NETBSD, binBash))
+        .isEqualTo(PathFragment.create("/bin/bash"));
     assertThat(determineShellExecutable(OS.OPENBSD, binBash))
         .isEqualTo(PathFragment.create("/bin/bash"));
     assertThat(determineShellExecutable(OS.WINDOWS, binBash))
