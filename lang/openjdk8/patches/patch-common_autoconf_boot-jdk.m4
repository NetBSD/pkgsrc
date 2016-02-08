$NetBSD: patch-common_autoconf_boot-jdk.m4,v 1.2 2016/02/08 14:45:39 ryoon Exp $

--- common/autoconf/boot-jdk.m4.orig	2016-02-08 13:44:13.000000000 +0000
+++ common/autoconf/boot-jdk.m4
@@ -334,16 +334,15 @@ AC_DEFUN_ONCE([BOOTJDK_SETUP_BOOT_JDK_AR
   # Maximum amount of heap memory.
   # Maximum stack size.
   if test "x$BOOT_JDK_BITS" = x32; then
-    JVM_MAX_HEAP=1100M
     STACK_SIZE=768
   else
     # Running Javac on a JVM on a 64-bit machine, takes more space since 64-bit
     # pointers are used. Apparently, we need to increase the heap and stack
     # space for the jvm. More specifically, when running javac to build huge
     # jdk batch
-    JVM_MAX_HEAP=1600M
     STACK_SIZE=1536
   fi
+  JVM_MAX_HEAP=800M
   ADD_JVM_ARG_IF_OK([-Xmx$JVM_MAX_HEAP],boot_jdk_jvmargs_big,[$JAVA])
   ADD_JVM_ARG_IF_OK([-XX:ThreadStackSize=$STACK_SIZE],boot_jdk_jvmargs_big,[$JAVA])
   ADD_JVM_ARG_IF_OK([-XX:PermSize=32m],boot_jdk_jvmargs_big,[$JAVA])
