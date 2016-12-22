$NetBSD: patch-hwaccess.c,v 1.1 2016/12/22 21:07:17 joerg Exp $

It is UB whether define() is not handled inside macro expansions.

--- hwaccess.c.orig	2016-12-22 15:40:41.401773946 +0000
+++ hwaccess.c
@@ -18,16 +18,40 @@
  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
  */
 
-#define IS_X86	(defined(__i386__) || defined(__x86_64__) || defined(__amd64__))
-#define IS_MIPS	(defined (__mips) || defined (__mips__) || defined (__MIPS__) || defined (mips))
-#define IS_PPC	(defined(__powerpc__) || defined(__powerpc64__) || defined(__ppc__) || defined(__ppc64__))
-#define IS_ARM	(defined (__arm__) || defined (_ARM))
+#if defined(__i386__) || defined(__x86_64__) || defined(__amd64__)
+#define IS_X86	1
+#else
+#define IS_X86	0
+#endif
+#if defined (__mips) || defined (__mips__) || defined (__MIPS__) || defined (mips)
+#define IS_MIPS	1
+#else
+#define IS_MIPS	0
+#endif
+#if defined(__powerpc__) || defined(__powerpc64__) || defined(__ppc__) || defined(__ppc64__)
+#define IS_PPC	1
+#else
+#define IS_PPC	0
+#endif
+#if defined (__arm__) || defined (_ARM)
+#define IS_ARM	1
+#else
+#define IS_ARM	0
+#endif
 #if !(IS_X86 || IS_MIPS || IS_PPC || IS_ARM)
 #error Unknown architecture
 #endif
 
-#define IS_LINUX	(defined(__gnu_linux__) || defined(__linux__))
-#define IS_MACOSX	(defined(__APPLE__) && defined(__MACH__))
+#if defined(__gnu_linux__) || defined(__linux__)
+#define IS_LINUX	1
+#else
+#define IS_LINUX	0
+#endif
+#if defined(__APPLE__) && defined(__MACH__)
+#define IS_MACOSX	1
+#else
+#define IS_MACOSX	0
+#endif
 #if !(IS_LINUX || IS_MACOSX || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__DJGPP__) || defined(__LIBPAYLOAD__) || defined(__sun))
 #error "Unknown operating system"
 #endif
@@ -45,8 +69,16 @@
 #include "flash.h"
 #include "hwaccess.h"
 
-#define USE_IOPL	(IS_LINUX || IS_MACOSX || defined(__NetBSD__) || defined(__OpenBSD__))
-#define USE_DEV_IO	(defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__))
+#if IS_LINUX || IS_MACOSX || defined(__NetBSD__) || defined(__OpenBSD__)
+#define USE_IOPL	1
+#else
+#define USE_IOPL	0
+#endif
+#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__))
+#define USE_DEV_IO	1
+#else
+#define USE_DEV_IO	0
+#endif
 
 #if IS_X86 && USE_DEV_IO
 int io_fd;
