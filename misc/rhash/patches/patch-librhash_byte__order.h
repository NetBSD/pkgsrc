$NetBSD: patch-librhash_byte__order.h,v 1.1 2015/02/23 18:26:12 joerg Exp $

--- librhash/byte_order.h.orig	2015-02-22 21:07:44.000000000 +0000
+++ librhash/byte_order.h
@@ -10,6 +10,8 @@
 
 #ifdef __GLIBC__
 # include <endian.h>
+#elif defined(__NetBSD__) || defined(__FreeBSD__)
+# include <sys/endian.h>
 #endif
 
 #ifdef __cplusplus
@@ -37,7 +39,8 @@ extern "C" {
 
 /* detect CPU endianness */
 #if (defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && \
-		__BYTE_ORDER == __LITTLE_ENDIAN) || \
+		__BYTE_ORDER == __LITTLE_ENDIAN) || (defined(_BYTE_ORDER) && defined(_LITTLE_ENDIAN) && \
+		_BYTE_ORDER == _LITTLE_ENDIAN) || \
 	defined(CPU_IA32) || defined(CPU_X64) || \
 	defined(__ia64) || defined(__ia64__) || defined(__alpha__) || defined(_M_ALPHA) || \
 	defined(vax) || defined(MIPSEL) || defined(_ARM_)
@@ -45,7 +48,8 @@ extern "C" {
 # define IS_BIG_ENDIAN 0
 # define IS_LITTLE_ENDIAN 1
 #elif (defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && \
-		__BYTE_ORDER == __BIG_ENDIAN) || \
+		__BYTE_ORDER == __BIG_ENDIAN) || (defined(_BYTE_ORDER) && defined(_BIG_ENDIAN) && \
+		_BYTE_ORDER == _BIG_ENDIAN) || \
 	defined(__sparc) || defined(__sparc__) || defined(sparc) || \
 	defined(_ARCH_PPC) || defined(_ARCH_PPC64) || defined(_POWER) || \
 	defined(__POWERPC__) || defined(POWERPC) || defined(__powerpc) || \
@@ -90,15 +94,15 @@ void rhash_swap_copy_u64_to_str(void* to
 void rhash_u32_mem_swap(unsigned *p, int length_in_u32);
 
 /* define bswap_32 */
-#if defined(__GNUC__) && defined(CPU_IA32) && !defined(__i386__)
+#if defined(__GNUC__) && (__GNUC__ >= 4) && ((__GNUC__ > 4 || __GNUC_MINOR__ >= 3) || defined(__clang__))
+/* for GCC >= 4.3 */
+# define bswap_32(x) __builtin_bswap32(x)
+#elif defined(__GNUC__) && defined(CPU_IA32) && !defined(__i386__)
 /* for intel x86 CPU */
 static inline uint32_t bswap_32(uint32_t x) {
 	__asm("bswap\t%0" : "=r" (x) : "0" (x));
 	return x;
 }
-#elif defined(__GNUC__)  && (__GNUC__ >= 4) && (__GNUC__ > 4 || __GNUC_MINOR__ >= 3)
-/* for GCC >= 4.3 */
-# define bswap_32(x) __builtin_bswap32(x)
 #elif (_MSC_VER > 1300) && (defined(CPU_IA32) || defined(CPU_X64)) /* MS VC */
 # define bswap_32(x) _byteswap_ulong((unsigned long)x)
 #elif !defined(__STRICT_ANSI__)
@@ -112,7 +116,7 @@ static inline uint32_t bswap_32(uint32_t
 	(((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
 #endif /* bswap_32 */
 
-#if defined(__GNUC__) && (__GNUC__ >= 4) && (__GNUC__ > 4 || __GNUC_MINOR__ >= 3)
+#if defined(__GNUC__) && (__GNUC__ >= 4) && ((__GNUC__ > 4 || __GNUC_MINOR__ >= 3) || defined(__clang__))
 # define bswap_64(x) __builtin_bswap64(x)
 #elif (_MSC_VER > 1300) && (defined(CPU_IA32) || defined(CPU_X64)) /* MS VC */
 # define bswap_64(x) _byteswap_uint64((__int64)x)
