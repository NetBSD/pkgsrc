$NetBSD: patch-src_third__party_mozjs-38_platform_x86__64_netbsd_build_js-confdefs.h,v 1.2 2017/05/29 14:44:47 ryoon Exp $

--- src/third_party/mozjs-45/platform/x86_64/netbsd/build/js-confdefs.h.orig	2016-02-11 12:42:39.272068631 +0000
+++ src/third_party/mozjs-45/platform/x86_64/netbsd/build/js-confdefs.h
@@ -19,7 +19,6 @@
 #define HAVE_CPUID_H 1
 #define HAVE_DIRENT_H 1
 #define HAVE_DLOPEN 1
-#define HAVE_ENDIAN_H 1
 #define HAVE_EXPM1 1
 #define HAVE_GETC_UNLOCKED 1
 #define HAVE_GETOPT_H 1
@@ -54,7 +53,6 @@
 #define JS_CODEGEN_X64 1
 #define JS_CPU_X64 1
 #define JS_DEFAULT_JITREPORT_GRANULARITY 3
-#define JS_HAVE_ENDIAN_H 1
 #define JS_HAVE_MACHINE_ENDIAN_H 1
 #define JS_POSIX_NSPR 1
 #define JS_PUNBOX64 1
