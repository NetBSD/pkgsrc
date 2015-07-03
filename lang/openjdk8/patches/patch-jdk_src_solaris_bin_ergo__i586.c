$NetBSD: patch-jdk_src_solaris_bin_ergo__i586.c,v 1.1 2015/07/03 20:40:59 fhajny Exp $

GCC compatability.

--- jdk/src/solaris/bin/ergo_i586.c.orig	2015-02-02 15:37:12.000000000 +0000
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
 
-#if defined(__linux__) || defined(_ALLBSD_SOURCE)
+#if (defined(__linux__) || defined(_ALLBSD_SOURCE)) || (defined(__solaris__) && defined(_GNU_SOURCE))
 
 /*
  * A utility method for asking the CPU about itself.
@@ -171,6 +173,7 @@ get_cpuid(uint32_t arg,
 #endif /* _LP64 */
 }
 
+#ifndef __solaris__
 /* The definition of a server-class machine for linux-i586 */
 jboolean
 ServerClassMachineImpl(void) {
@@ -197,6 +200,7 @@ ServerClassMachineImpl(void) {
            (result == JNI_TRUE ? "true" : "false"));
   return result;
 }
+#endif /* !__solaris__ */
 #endif /* __linux__ || _ALLBSD_SOURCE */
 
 /*
