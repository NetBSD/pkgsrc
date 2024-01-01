$NetBSD: patch-src_main_java_com_google_devtools_build_lib_jni_JniLoader.java,v 1.1 2024/01/01 12:00:58 ryoon Exp $

--- src/main/java/com/google/devtools/build/lib/jni/JniLoader.java.orig	2023-11-30 05:46:49.398016529 +0000
+++ src/main/java/com/google/devtools/build/lib/jni/JniLoader.java
@@ -39,6 +39,7 @@ public final class JniLoader {
       switch (OS.getCurrent()) {
         case LINUX:
         case FREEBSD:
+        case NETBSD:
         case OPENBSD:
         case UNKNOWN:
           loadLibrary("main/native/libunix_jni.so");
