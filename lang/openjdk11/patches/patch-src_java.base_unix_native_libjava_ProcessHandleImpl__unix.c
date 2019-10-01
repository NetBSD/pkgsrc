$NetBSD: patch-src_java.base_unix_native_libjava_ProcessHandleImpl__unix.c,v 1.1 2019/10/01 12:36:34 tnn Exp $

waitid(2) is available from NetBSD>=7.99.27

--- src/java.base/unix/native/libjava/ProcessHandleImpl_unix.c.orig	2019-09-19 12:22:38.000000000 +0000
+++ src/java.base/unix/native/libjava/ProcessHandleImpl_unix.c
@@ -259,7 +259,7 @@ Java_java_lang_ProcessHandleImpl_waitFor
             return status;
         }
      } else {
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || (defined(__NetBSD__) && __NetBSD_Version < 799002700)
         return os_waitForProcessExitNoReap(pid);
 #else
         /*
