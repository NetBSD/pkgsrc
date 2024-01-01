$NetBSD: patch-src_test_java_com_google_devtools_build_lib_runtime_commands_CleanCommandRecommendsAsyncTest.java,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/test/java/com/google/devtools/build/lib/runtime/commands/CleanCommandRecommendsAsyncTest.java.orig	2023-11-30 05:52:55.919903525 +0000
+++ src/test/java/com/google/devtools/build/lib/runtime/commands/CleanCommandRecommendsAsyncTest.java
@@ -51,6 +51,7 @@ public class CleanCommandRecommendsAsync
           {/* asyncOnCommandLine= */ true, OS.WINDOWS, false},
           {/* asyncOnCommandLine= */ true, OS.DARWIN, false},
           {/* asyncOnCommandLine= */ true, OS.FREEBSD, false},
+          {/* asyncOnCommandLine= */ true, OS.NETBSD, false},
           {/* asyncOnCommandLine= */ true, OS.OPENBSD, false},
           {/* asyncOnCommandLine= */ true, OS.UNKNOWN, false},
 
@@ -59,6 +60,7 @@ public class CleanCommandRecommendsAsync
           {/* asyncOnCommandLine= */ false, OS.WINDOWS, false},
           {/* asyncOnCommandLine= */ false, OS.DARWIN, true},
           {/* asyncOnCommandLine= */ false, OS.FREEBSD, true},
+          {/* asyncOnCommandLine= */ false, OS.NETBSD, true},
           {/* asyncOnCommandLine= */ false, OS.OPENBSD, true},
           {/* asyncOnCommandLine= */ false, OS.UNKNOWN, false},
         });
