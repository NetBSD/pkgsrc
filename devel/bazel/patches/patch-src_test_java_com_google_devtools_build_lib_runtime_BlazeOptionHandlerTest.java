$NetBSD: patch-src_test_java_com_google_devtools_build_lib_runtime_BlazeOptionHandlerTest.java,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/test/java/com/google/devtools/build/lib/runtime/BlazeOptionHandlerTest.java.orig	2023-11-28 16:50:58.267394320 +0000
+++ src/test/java/com/google/devtools/build/lib/runtime/BlazeOptionHandlerTest.java
@@ -117,6 +117,7 @@ public class BlazeOptionHandlerTest {
     structuredArgs.put("c0:windows", new RcChunkOfArgs("rc1", ImmutableList.of("command_windows")));
     structuredArgs.put("c0:macos", new RcChunkOfArgs("rc1", ImmutableList.of("command_macos")));
     structuredArgs.put("c0:freebsd", new RcChunkOfArgs("rc1", ImmutableList.of("command_freebsd")));
+    structuredArgs.put("c0:netbsd", new RcChunkOfArgs("rc1", ImmutableList.of("command_netbsd")));
     structuredArgs.put("c0:openbsd", new RcChunkOfArgs("rc1", ImmutableList.of("command_openbsd")));
     structuredArgs.put(
         "c0:platform_config",
@@ -283,6 +284,9 @@ public class BlazeOptionHandlerTest {
       case FREEBSD:
         assertThat(parser.getResidue()).containsExactly("command_freebsd");
         break;
+      case NETBSD:
+        assertThat(parser.getResidue()).containsExactly("command_netbsd");
+        break;
       case OPENBSD:
         assertThat(parser.getResidue()).containsExactly("command_openbsd");
         break;
@@ -311,6 +315,9 @@ public class BlazeOptionHandlerTest {
       case FREEBSD:
         assertThat(parser.getResidue()).containsExactly("command_freebsd");
         break;
+      case NETBSD:
+        assertThat(parser.getResidue()).containsExactly("command_netbsd");
+        break;
       case OPENBSD:
         assertThat(parser.getResidue()).containsExactly("command_openbsd");
         break;
