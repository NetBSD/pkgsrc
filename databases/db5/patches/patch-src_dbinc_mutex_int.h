$NetBSD: patch-src_dbinc_mutex_int.h,v 1.1 2019/02/19 15:18:19 hauke Exp $

* adds support for mutexes on aarch64
* fixes build failure on MIPS arch with -mips1.

--- src/dbinc/mutex_int.h.orig	2010-04-12 20:25:22.000000000 +0000
+++ src/dbinc/mutex_int.h
@@ -491,6 +491,43 @@ typedef unsigned char tsl_t;
 #endif
 
 /*********************************************************************
+ * AARCH64/gcc assembly.
+ *********************************************************************/
+
+#ifdef HAVE_MUTEX_AARCH64_GCC_ASSEMBLY
+typedef unsigned int tsl_t;
+
+#ifdef LOAD_ACTUAL_MUTEX_CODE
+static inline int
+MUTEX_SET(tsl_t *tsl) {
+	register tsl_t *__l = tsl;
+	register tsl_t __r;
+	__asm__ volatile(
+		"1:	ldxr	%w0,[%1]\n"
+		"	cbnz	%w0,2f\n"
+		"	stxr	%w0,%w2,[%1]\n"
+		"	cbnz	%w0,1b\n"
+		"	dmb	st\n"
+		"2:"
+		: "=&r"(__r)
+		: "r"(__l), "r"(1)
+		: "memory");
+
+	return !__r;
+}
+
+static inline int
+MUTEX_UNSET(tsl_t *tsl) {
+	__asm__ volatile(
+		"	dsb	sy\n" ::: "memory");
+	return *tsl = 0;
+}
+
+#define	MUTEX_INIT(tsl)		(MUTEX_UNSET(tsl), 0)
+#endif
+#endif
+
+/*********************************************************************
  * HPPA/gcc assembly.
  *********************************************************************/
 #ifdef HAVE_MUTEX_HPPA_GCC_ASSEMBLY
@@ -778,10 +815,14 @@ MUTEX_SET(tsl_t *tsl) {
 static inline void
 MUTEX_UNSET(tsl_t *tsl) {
 	__asm__ volatile(
+	       "       .set push           \n"
+	       "       .set mips2          \n"
 	       "       .set noreorder      \n"
+	       "       .set nomacro        \n"
 	       "       sync                \n"
 	       "       sw      $0, %0      \n"
 	       "       .set reorder        \n"
+	       "       .set pop            \n"
 	       : "=m" (*tsl)
 	       : "m" (*tsl)
 	       : "memory");
