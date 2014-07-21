$NetBSD: patch-jdk_src_solaris_native_java_lang_UNIXProcess__md.c,v 1.1 2014/07/21 00:15:41 ryoon Exp $

* NetBSD 5 has no posix_spawn.

--- jdk/src/solaris/native/java/lang/UNIXProcess_md.c.orig	2014-06-14 20:38:31.000000000 +0000
+++ jdk/src/solaris/native/java/lang/UNIXProcess_md.c
@@ -48,9 +48,15 @@
 #include <signal.h>
 #include <string.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #if defined(__solaris__) || defined(_ALLBSD_SOURCE)
+#if !defined(__NetBSD__) || (__NetBSD_Version__ >= 600000000)
 #include <spawn.h>
 #endif
+#endif
 
 #include "childproc.h"
 
@@ -460,6 +466,7 @@ forkChild(ChildStuff *c) {
 }
 
 #if defined(__solaris__) || defined(_ALLBSD_SOURCE)
+#if !defined(__NetBSD__) || (__NetBSD_Version__ >= 600000000)
 static pid_t
 spawnChild(JNIEnv *env, jobject process, ChildStuff *c, const char *helperpath) {
     pid_t resultPid;
@@ -543,6 +550,7 @@ spawnChild(JNIEnv *env, jobject process,
     return resultPid;
 }
 #endif
+#endif
 
 /*
  * Start a child process running function childProcess.
@@ -556,9 +564,11 @@ startChild(JNIEnv *env, jobject process,
       case MODE_FORK:
         return forkChild(c);
 #if defined(__solaris__) || defined(_ALLBSD_SOURCE)
+#if !defined(__NetBSD__) || (__NetBSD_Version__ >= 600000000)
       case MODE_POSIX_SPAWN:
         return spawnChild(env, process, c, helperpath);
 #endif
+#endif
       default:
         return -1;
     }
