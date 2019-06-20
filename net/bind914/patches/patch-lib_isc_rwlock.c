$NetBSD: patch-lib_isc_rwlock.c,v 1.2 2019/06/20 02:16:53 taca Exp $

* Platform change from NetBSD base.

--- lib/isc/rwlock.c.orig	2019-06-04 15:20:04.000000000 +0000
+++ lib/isc/rwlock.c
@@ -58,7 +58,8 @@
 # define isc_rwlock_pause() __asm__ __volatile__ ("yield")
 #elif defined(sun) && (defined(__sparc) || defined(__sparc__))
 # define isc_rwlock_pause() smt_pause()
-#elif defined(__sparc) || defined(__sparc__)
+/* Disable pause, only works on v9 */
+#elif defined(__sparc) || defined(__sparc__) && defined(notdef)
 # define isc_rwlock_pause() __asm__ __volatile__ ("pause")
 #elif defined(__ppc__) || defined(_ARCH_PPC)  ||			\
 	defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_POWER)
