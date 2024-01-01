$NetBSD: patch-src_test_java_com_google_devtools_build_lib_bazel_repository_LocalConfigPlatformFunctionTest.java,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/test/java/com/google/devtools/build/lib/bazel/repository/LocalConfigPlatformFunctionTest.java.orig	2023-11-28 16:47:43.460647791 +0000
+++ src/test/java/com/google/devtools/build/lib/bazel/repository/LocalConfigPlatformFunctionTest.java
@@ -87,6 +87,7 @@ public class LocalConfigPlatformFunction
           new Object[] {OS.LINUX, "@platforms//os:linux"},
           new Object[] {OS.DARWIN, "@platforms//os:osx"},
           new Object[] {OS.FREEBSD, "@platforms//os:freebsd"},
+          new Object[] {OS.NETBSD, "@platforms//os:netbsd"},
           new Object[] {OS.OPENBSD, "@platforms//os:openbsd"},
           new Object[] {OS.WINDOWS, "@platforms//os:windows"});
     }
