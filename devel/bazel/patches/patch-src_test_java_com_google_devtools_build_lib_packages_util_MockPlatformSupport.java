$NetBSD: patch-src_test_java_com_google_devtools_build_lib_packages_util_MockPlatformSupport.java,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/test/java/com/google/devtools/build/lib/packages/util/MockPlatformSupport.java.orig	2023-11-28 16:47:15.246726723 +0000
+++ src/test/java/com/google/devtools/build/lib/packages/util/MockPlatformSupport.java
@@ -136,6 +136,10 @@ public class MockPlatformSupport {
         "    constraint_setting = ':os',",
         ")",
         "constraint_value(",
+        "    name = 'netbsd',",
+        "    constraint_setting = ':os',",
+        ")",
+        "constraint_value(",
         "    name = 'openbsd',",
         "    constraint_setting = ':os',",
         ")");
