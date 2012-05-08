$NetBSD: patch-ipc_chromium_src_chrome_common_ipc__message__utils.h,v 1.2 2012/05/08 19:29:37 martin Exp $

# Reported upstream: https://bugzilla.mozilla.org/show_bug.cgi?id=753046

--- ipc/chromium/src/chrome/common/ipc_message_utils.h.orig	2011-12-20 23:28:19.000000000 +0000
+++ ipc/chromium/src/chrome/common/ipc_message_utils.h
@@ -195,7 +195,7 @@
 };
 #endif
 
-#if !(defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_WIN) || (defined(OS_LINUX) && defined(ARCH_CPU_64_BITS)) || defined(ARCH_CPU_S390))
+#if !(defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_WIN) || ((defined(OS_FREEBSD) || defined(OS_DRAGONFLY) || defined(OS_NETBSD) || defined(OS_LINUX)) && defined(ARCH_CPU_64_BITS)) || defined(ARCH_CPU_S390))
 // There size_t is a synonym for |unsigned long| ...
 template <>
 struct ParamTraits<size_t> {
@@ -248,7 +248,7 @@
 };
 #endif  // defined(OS_MACOSX)
 
-#if !(defined(OS_LINUX) && defined(ARCH_CPU_64_BITS))
+#if !((defined(OS_FREEBSD) || defined(OS_DRAGONFLY) || defined(OS_NETBSD) || defined(OS_LINUX)) && defined(ARCH_CPU_64_BITS))
 // int64 is |long int| on 64-bit systems, uint64 is |unsigned long|
 template <>
 struct ParamTraits<int64> {
