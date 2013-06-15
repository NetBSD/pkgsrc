$NetBSD: patch-jdk_src_solaris_bin_ergo__i586.c,v 1.1 2013/06/15 09:31:06 jperkin Exp $

GCC compatability.

--- jdk/src/solaris/bin/ergo_i586.c.orig	2013-06-12 00:28:04.421609606 +0000
+++ jdk/src/solaris/bin/ergo_i586.c
@@ -27,7 +27,7 @@
 
 static unsigned long physical_processors(void);
 
-#ifdef __solaris__
+#if defined(__solaris__) && !defined(_GNU_SOURCE)
 
 /*
  * A utility method for asking the CPU about itself.
@@ -76,7 +76,9 @@ get_cpuid(uint32_t arg,
   asm(" popl    %ebx");
 #endif /* LP64 */
 }
+#endif /* __solaris__ && !_GNU_SOURCE */
 
+#ifdef __solaris__
 /* The definition of a server-class machine for solaris-i586/amd64 */
 jboolean
 ServerClassMachineImpl(void) {
@@ -106,7 +108,7 @@ ServerClassMachineImpl(void) {
 
 #endif /* __solaris__ */
 
-#if !defined(MACOSX) && (defined(__linux__) || defined(_ALLBSD_SOURCE))
+#if !defined(MACOSX) && (defined(__linux__) || defined(_ALLBSD_SOURCE)) || (defined(__solaris__) && defined(_GNU_SOURCE))
 
 /*
  * A utility method for asking the CPU about itself.
@@ -177,6 +179,7 @@ get_cpuid(uint32_t arg,
 #define OSNAMEPREFIX "bsd_"
 #endif
 
+#ifndef __solaris__
 /* The definition of a server-class machine for linux-i586 */
 jboolean
 ServerClassMachineImpl(void) {
@@ -203,6 +206,7 @@ ServerClassMachineImpl(void) {
            (result == JNI_TRUE ? "true" : "false"));
   return result;
 }
+#endif /* !__solaris__ */
 #endif /* !MACOSX && (__linux__ || _ALLBSD_SOURCE) */
 
 /*
