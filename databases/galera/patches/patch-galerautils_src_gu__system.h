$NetBSD: patch-galerautils_src_gu__system.h,v 1.1 2023/01/13 16:08:03 wiz Exp $

NetBSD support.
https://github.com/codership/galera/pull/632

--- galerautils/src/gu_system.h.orig	2022-11-02 06:09:14.000000000 +0000
+++ galerautils/src/gu_system.h
@@ -23,7 +23,7 @@ extern "C" {
 
 #if defined(__sun__)
 # define GU_SYS_PROGRAM_NAME getexecname ()
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 # define GU_SYS_PROGRAM_NAME getprogname ()
 #elif defined(__linux__)
 # define GU_SYS_PROGRAM_NAME program_invocation_name
