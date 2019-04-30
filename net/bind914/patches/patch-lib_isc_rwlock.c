$NetBSD: patch-lib_isc_rwlock.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Platform change from NetBSD base.

--- lib/isc/rwlock.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/isc/rwlock.c
@@ -54,11 +54,12 @@
 # define isc_rwlock_pause() __asm__ __volatile__ ("rep; nop")
 #elif defined(__ia64__)
 # define isc_rwlock_pause() __asm__ __volatile__ ("hint @pause")
-#elif defined(__arm__)
+#elif defined(__arm__) && defined(_ARM_ARCH_6)
 # define isc_rwlock_pause() __asm__ __volatile__ ("yield")
 #elif defined(sun) && (defined(__sparc) || defined(__sparc__))
 # define isc_rwlock_pause() smt_pause()
-#elif defined(__sparc) || defined(__sparc__)
+/* Disable pause, only works on v9 */
+#elif (defined(__sparc) || defined(__sparc__)) && defined(notdef)
 # define isc_rwlock_pause() __asm__ __volatile__ ("pause")
 #elif defined(__ppc__) || defined(_ARCH_PPC)  ||			\
 	defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_POWER)
