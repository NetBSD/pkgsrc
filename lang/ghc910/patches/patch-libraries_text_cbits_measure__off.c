$NetBSD: patch-libraries_text_cbits_measure__off.c,v 1.1 2025/01/29 13:21:54 pho Exp $

Workaround for http://gnats.netbsd.org/58379

We really need to disable the AVX-512 code path, otherwise we end up
producing non-working binary. Patching it away is better than

    CFLAGS+= -D__STDC_NO_ATOMICS__

because AVX-512 being disabled is only a side effect of the macro being
defined. When the upstream code changes we can be promptly notified by the
patch not applying cleanly.

--- libraries/text/cbits/measure_off.c.orig	2025-01-08 14:36:12.967927622 +0000
+++ libraries/text/cbits/measure_off.c
@@ -13,10 +13,7 @@
 #endif
 #include <stdbool.h>
 
-// stdatomic.h has been introduces in gcc 4.9
-#if !(__GNUC__ >= 5 || __GNUC__ == 4 && __GNUC_MINOR__ >= 9 || defined(__clang_major__))
 #define __STDC_NO_ATOMICS__
-#endif
 
 #ifndef __STDC_NO_ATOMICS__
 #include <stdatomic.h>
