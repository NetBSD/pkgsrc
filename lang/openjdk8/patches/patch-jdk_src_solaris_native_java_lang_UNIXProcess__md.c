$NetBSD: patch-jdk_src_solaris_native_java_lang_UNIXProcess__md.c,v 1.1 2015/02/08 08:41:25 tnn Exp $

* NetBSD 5 has no posix_spawn.

--- jdk/src/solaris/native/java/lang/UNIXProcess_md.c.orig	2015-02-02 15:37:12.000000000 +0000
+++ jdk/src/solaris/native/java/lang/UNIXProcess_md.c
@@ -44,9 +44,15 @@
 #include <signal.h>
 #include <string.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #if defined(__solaris__) || defined(_ALLBSD_SOURCE) || defined(_AIX)
+#if !defined(__NetBSD__) || (__NetBSD_Version__ >= 600000000)
 #include <spawn.h>
 #endif
+#endif
 
 #include "childproc.h"
 
@@ -456,6 +462,7 @@ forkChild(ChildStuff *c) {
 }
 
 #if defined(__solaris__) || defined(_ALLBSD_SOURCE) || defined(_AIX)
+#if !defined(__NetBSD__) || (__NetBSD_Version__ >= 600000000)
 static pid_t
 spawnChild(JNIEnv *env, jobject process, ChildStuff *c, const char *helperpath) {
     pid_t resultPid;
@@ -539,6 +546,7 @@ spawnChild(JNIEnv *env, jobject process,
     return resultPid;
 }
 #endif
+#endif
 
 /*
  * Start a child process running function childProcess.
@@ -552,9 +560,11 @@ startChild(JNIEnv *env, jobject process,
       case MODE_FORK:
         return forkChild(c);
 #if defined(__solaris__) || defined(_ALLBSD_SOURCE) || defined(_AIX)
+#if !defined(__NetBSD__) || (__NetBSD_Version__ >= 600000000)
       case MODE_POSIX_SPAWN:
         return spawnChild(env, process, c, helperpath);
 #endif
+#endif
       default:
         return -1;
     }
