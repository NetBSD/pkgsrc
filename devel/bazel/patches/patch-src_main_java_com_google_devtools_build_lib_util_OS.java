$NetBSD: patch-src_main_java_com_google_devtools_build_lib_util_OS.java,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/main/java/com/google/devtools/build/lib/util/OS.java.orig	1979-12-31 15:00:00.000000000 +0000
+++ src/main/java/com/google/devtools/build/lib/util/OS.java
@@ -21,12 +21,13 @@ import java.util.EnumSet;
 public enum OS {
   DARWIN("osx", "Mac OS X"),
   FREEBSD("freebsd", "FreeBSD"),
+  NETBSD("netbsd", "NetBSD"),
   OPENBSD("openbsd", "OpenBSD"),
   LINUX("linux", "Linux"),
   WINDOWS("windows", "Windows"),
   UNKNOWN("unknown", "");
 
-  private static final EnumSet<OS> POSIX_COMPATIBLE = EnumSet.of(DARWIN, FREEBSD, OPENBSD, LINUX);
+  private static final EnumSet<OS> POSIX_COMPATIBLE = EnumSet.of(DARWIN, FREEBSD, NETBSD, OPENBSD, LINUX);
 
   private final String canonicalName;
   private final String detectionName;
