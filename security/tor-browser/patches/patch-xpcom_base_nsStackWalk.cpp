$NetBSD: patch-xpcom_base_nsStackWalk.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

* Replace XP_MACOSX with XP_DARWIN as the former is not defined when
  the toolkit is not cocoa.

--- xpcom/base/nsStackWalk.cpp.orig	2015-05-04 00:43:35.000000000 +0000
+++ xpcom/base/nsStackWalk.cpp
@@ -34,12 +34,12 @@ static CriticalAddress gCriticalAddress;
 #define _GNU_SOURCE
 #endif
 
-#if defined(HAVE_DLOPEN) || defined(XP_MACOSX)
+#if defined(HAVE_DLOPEN) || defined(XP_DARWIN)
 #include <dlfcn.h>
 #endif
 
-#define NSSTACKWALK_SUPPORTS_MACOSX \
-  (defined(XP_MACOSX) && \
+#define NSSTACKWALK_SUPPORTS_DARWIN \
+  (defined(XP_DARWIN) && \
    (defined(__i386) || defined(__ppc__) || defined(HAVE__UNWIND_BACKTRACE)))
 
 #define NSSTACKWALK_SUPPORTS_LINUX \
@@ -47,7 +47,7 @@ static CriticalAddress gCriticalAddress;
    ((defined(__GNUC__) && (defined(__i386) || defined(PPC))) || \
     defined(HAVE__UNWIND_BACKTRACE)))
 
-#if NSSTACKWALK_SUPPORTS_MACOSX
+#if NSSTACKWALK_SUPPORTS_DARWIN
 #include <pthread.h>
 #include <CoreServices/CoreServices.h>
 
@@ -830,7 +830,7 @@ NS_DescribeCodeAddress(void* aPC, nsCode
 }
 
 // i386 or PPC Linux stackwalking code
-#elif HAVE_DLADDR && (HAVE__UNWIND_BACKTRACE || NSSTACKWALK_SUPPORTS_LINUX || NSSTACKWALK_SUPPORTS_MACOSX)
+#elif HAVE_DLADDR && (HAVE__UNWIND_BACKTRACE || NSSTACKWALK_SUPPORTS_LINUX || NSSTACKWALK_SUPPORTS_DARWIN)
 
 #include <stdlib.h>
 #include <string.h>
@@ -901,7 +901,7 @@ FramePointerStackWalk(NS_WalkStackCallba
         (long(next) & 3)) {
       break;
     }
-#if (defined(__ppc__) && defined(XP_MACOSX)) || defined(__powerpc64__)
+#if (defined(__ppc__) && defined(XP_DARWIN)) || defined(__powerpc64__)
     // ppc mac or powerpc64 linux
     void* pc = *(bp + 2);
     bp += 3;
@@ -931,7 +931,7 @@ FramePointerStackWalk(NS_WalkStackCallba
 }
 
 #define X86_OR_PPC (defined(__i386) || defined(PPC) || defined(__ppc__))
-#if X86_OR_PPC && (NSSTACKWALK_SUPPORTS_MACOSX || NSSTACKWALK_SUPPORTS_LINUX) // i386 or PPC Linux or Mac stackwalking code
+#if X86_OR_PPC && (NSSTACKWALK_SUPPORTS_DARWIN || NSSTACKWALK_SUPPORTS_LINUX) // i386 or PPC Linux or Mac stackwalking code
 
 XPCOM_API(nsresult)
 NS_StackWalk(NS_WalkStackCallback aCallback, uint32_t aSkipFrames,
