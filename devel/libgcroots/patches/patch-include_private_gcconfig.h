$NetBSD: patch-include_private_gcconfig.h,v 1.1 2019/11/20 21:24:33 maya Exp $

Add support for netbsd/aarch64, based on netbsd/arm32 code within the same file.

--- include/private/gcconfig.h.orig	2008-02-19 15:51:24.000000000 +0000
+++ include/private/gcconfig.h
@@ -62,6 +62,14 @@
 # endif
 
 /* Determine the machine type: */
+# if defined(__aarch64__)
+#    define AARCH64
+#    if !defined(LINUX) && !defined(DARWIN) && !defined(FREEBSD) \
+        && !defined(NETBSD) && !defined(NN_BUILD_TARGET_PLATFORM_NX)
+#      define NOSYS
+#      define mach_type_known
+#    endif
+# endif
 # if defined(__arm__) || defined(__thumb__)
 #    define ARM32
 #    if !defined(LINUX) && !defined(NETBSD)
@@ -99,6 +107,10 @@
 #    define ARM32
 #    define mach_type_known
 # endif
+# if defined(NETBSD) && defined(__aarch64__)
+#    define AARCH64
+#    define mach_type_known
+# endif
 # if defined(NETBSD) && defined(__sh__)
 #    define SH
 #    define mach_type_known
@@ -1724,6 +1736,60 @@
 #   endif
 # endif
 
+
+# ifdef ARM32
+#   define CPP_WORDSZ 64
+#   define MACH_TYPE "AARCH64"
+#   define ALIGNMENT 8
+#   ifdef NETBSD
+#       define OS_TYPE "NETBSD"
+#       define HEURISTIC2
+#	ifdef __ELF__
+#          define DATASTART GC_data_start
+#	   define DYNAMIC_LOADING
+#	else
+           extern char etext[];
+#          define DATASTART ((ptr_t)(etext))
+#	endif
+#   endif
+#   ifdef LINUX
+#       define OS_TYPE "LINUX"
+#       define LINUX_STACKBOTTOM
+#       ifdef __ELF__
+#            define DYNAMIC_LOADING
+#	     include <features.h>
+#	     if defined(__GLIBC__) && __GLIBC__ >= 2
+#		 define SEARCH_FOR_DATA_START
+#	     else
+     	         extern char **__environ;
+#                define DATASTART ((ptr_t)(&__environ))
+			      /* hideous kludge: __environ is the first */
+			      /* word in crt0.o, and delimits the start */
+			      /* of the data segment, no matter which   */
+			      /* ld options were passed through.        */
+			      /* We could use _etext instead, but that  */
+			      /* would include .rodata, which may       */
+			      /* contain large read-only data tables    */
+			      /* that we'd rather not scan.		*/
+#	     endif
+	     extern int _end[];
+#	     define DATAEND (_end)
+#	else
+	     extern int etext[];
+#            define DATASTART ((ptr_t)((((word) (etext)) + 0xfff) & ~0xfff))
+#       endif
+#   endif
+#   ifdef NOSYS
+      /* __data_start is usually defined in the target linker script.  */
+      extern int __data_start[];
+#     define DATASTART (ptr_t)(__data_start)
+      /* __stack_base__ is set in newlib/libc/sys/arm/crt0.S  */
+      extern void *__stack_base__;
+#     define STACKBOTTOM ((ptr_t) (__stack_base__))
+#   endif
+#endif
+
+
 # ifdef ARM32
 #   define CPP_WORDSZ 32
 #   define MACH_TYPE "ARM32"
