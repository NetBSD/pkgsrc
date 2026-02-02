$NetBSD: patch-libraries_text_cbits_measure__off.c,v 1.2 2026/02/02 22:52:49 wiz Exp $

Workaround for http://gnats.netbsd.org/58379

We really need to disable the AVX-512 code path, otherwise we end up
producing non-working binary. Patching it away is better than

    CFLAGS+= -D__STDC_NO_ATOMICS__

because AVX-512 being disabled is only a side effect of the macro being
defined. When the upstream code changes we can be promptly notified by the
patch not applying cleanly.

This was fixed for NetBSD 11, but no 10.x or 9.x releases yet (though it was
pulled up), see PR 57661.

--- libraries/text/cbits/measure_off.c.orig	2024-05-10 05:07:47.000000000 +0000
+++ libraries/text/cbits/measure_off.c
@@ -13,9 +13,13 @@
 #endif
 #include <stdbool.h>
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
 // stdatomic.h has been introduces in gcc 4.9
-#if !(__GNUC__ >= 5 || __GNUC__ == 4 && __GNUC_MINOR__ >= 9 || defined(__clang_major__))
+#if !(__GNUC__ >= 5 || __GNUC__ == 4 && __GNUC_MINOR__ >= 9 || defined(__clang_major__)) || (defined(__NetBSD__) && (__NetBSD_Version__ < 1100000000))
 #define __STDC_NO_ATOMICS__
 #endif
 
 #ifndef __STDC_NO_ATOMICS__
