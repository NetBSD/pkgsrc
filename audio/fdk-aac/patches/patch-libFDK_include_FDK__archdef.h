$NetBSD: patch-libFDK_include_FDK__archdef.h,v 1.1 2023/05/28 09:03:03 tnn Exp $

Don't redefine system reserved macro, it breaks <sys/cdefs.h>

--- libFDK/include/FDK_archdef.h.orig	2021-04-28 12:45:10.000000000 +0000
+++ libFDK/include/FDK_archdef.h
@@ -114,8 +114,8 @@ amm-info@iis.fraunhofer.de
 #define __x86__
 #endif
 
-#if defined(_M_ARM) && !defined(__arm__) || defined(__aarch64__) || defined(_M_ARM64)
-#define __arm__
+#if !defined(__arm__) && (defined(_M_ARM) || defined(__aarch64__) || defined(_M_ARM64))
+#define __arm__ 1
 #endif
 
 #if defined(_ARCH_PPC) && !defined(__powerpc__)
