$NetBSD: patch-backup_libcd64_cd64io.h,v 1.2 2019/07/07 22:47:57 wiz Exp $

Patch from upstream to improve build on NetBSD.

--- backup/libcd64/cd64io.h.orig	2018-03-07 11:09:59.000000000 +0000
+++ backup/libcd64/cd64io.h
@@ -30,32 +30,15 @@ int cd64_xfer_portdev(struct cd64_t *cd6
 #endif
 
 #ifdef CD64_USE_RAWIO
-/* #define REALLY_SLOW_IO */
-#if defined __linux__ && (defined __i386__ || defined __x86_64__)
+#ifdef __linux__
 #include <sys/io.h>
 #endif
-#if (defined __OpenBSD__ || defined __NetBSD__) && (defined __i386__ || defined __x86_64__)
+#if defined __OpenBSD__ || defined __NetBSD__
 #include <sys/types.h>
 #include <machine/sysarch.h>
-#include <machine/pio.h>
-/* pio.h defines several I/O functions & macros, including the macros inb() and
- * outb(). This shows that using a bit of inline assembly is not such a bad idea
- * at all. */
-#undef inb
-#define inb(port) __inb(port)
-#undef outb
-#define outb(data, port) __outb(port, data)
 #endif
 #ifdef __FreeBSD__
 #include <fcntl.h>
-#include <machine/cpufunc.h>
-/* Almost the same story as under OpenBSD. cpufunc.h defines the macros inb()
- * and outb(). We redefine them. Be sure _POSIX_SOURCE is not defined before
- * including <machine/cpufunc.h>. */
-#undef inb
-#define inb(port) inbv(port)
-#undef outb
-#define outb(data, port) outbv(port, data)
 #endif
 #ifdef __BEOS__
 #include <fcntl.h>
@@ -68,24 +51,6 @@ int cd64_xfer_portdev(struct cd64_t *cd6
 #pragma warning(pop)
 #define F_OK 0
 #endif
-#ifdef __MSDOS__
-#include <pc.h>                                 /* inportb() & outportb() */
-#define inb(port) inportb(port)
-#define outb(data, port) outportb(port, data)
-#endif
-#if defined _WIN32 || defined __CYGWIN__
-#ifdef _MSC_VER
-#pragma warning(push)
-#pragma warning(disable: 4255) /* 'function' : no function prototype given: converting '()' to '(void)' */
-#pragma warning(disable: 4668) /* 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives' */
-#pragma warning(disable: 4820) /* 'bytes' bytes padding added after construct 'member_name' */
-#endif
-#include <windows.h>                            /* defines _WIN32 (checks for   */
-#ifdef _MSC_VER                                 /*  __CYGWIN__ must come first) */
-#pragma warning(pop)
-#endif
-#endif /* _WIN32 || __CYGWIN__ */
-
 int cd64_open_rawio(struct cd64_t *cd64);
 int cd64_close_rawio(struct cd64_t *cd64);
 int cd64_xfer_rawio(struct cd64_t *cd64, uint8_t *wr, uint8_t *rd, int delayms);
@@ -99,8 +64,8 @@ int cd64_xfer_rawio(struct cd64_t *cd64,
 #pragma warning(disable: 4668) /* 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives' */
 #pragma warning(disable: 4820) /* 'bytes' bytes padding added after construct 'member_name' */
 #endif
-#include <windows.h>
-#ifdef _MSC_VER
+#include <windows.h>                            /* defines _WIN32 (checks for   */
+#ifdef _MSC_VER                                 /*  __CYGWIN__ must come first) */
 #pragma warning(pop)
 #endif
 #define MSLEEP(x) Sleep(x)
