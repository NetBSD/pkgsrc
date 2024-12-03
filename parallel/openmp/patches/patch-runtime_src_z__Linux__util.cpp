$NetBSD: patch-runtime_src_z__Linux__util.cpp,v 1.1 2024/12/03 11:27:02 jperkin Exp $

SunOS uses pthread_attr_get_np() too.

--- runtime/src/z_Linux_util.cpp.orig	2024-12-03 11:24:49.291803482 +0000
+++ runtime/src/z_Linux_util.cpp
@@ -460,7 +460,7 @@ static kmp_int32 __kmp_set_stack_info(in
     /* Fetch the real thread attributes */
     status = pthread_attr_init(&attr);
     KMP_CHECK_SYSFAIL("pthread_attr_init", status);
-#if KMP_OS_DRAGONFLY || KMP_OS_FREEBSD || KMP_OS_NETBSD
+#if KMP_OS_DRAGONFLY || KMP_OS_FREEBSD || KMP_OS_NETBSD || KMP_OS_SOLARIS
     status = pthread_attr_get_np(pthread_self(), &attr);
     KMP_CHECK_SYSFAIL("pthread_attr_get_np", status);
 #else
