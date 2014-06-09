$NetBSD: patch-alsamixer_volume__mapping.c,v 1.1 2014/06/09 12:34:26 ryoon Exp $

* NetBSD has no exp10()

--- alsamixer/volume_mapping.c.orig	2013-07-09 15:28:37.000000000 +0000
+++ alsamixer/volume_mapping.c
@@ -37,10 +37,10 @@
 #include <stdbool.h>
 #include "volume_mapping.h"
 
-#ifdef __UCLIBC__
+#if defined(__UCLIBC__) || defined(__NetBSD__)
 /* 10^x = 10^(log e^x) = (e^x)^log10 = e^(x * log 10) */
 #define exp10(x) (exp((x) * log(10)))
-#endif /* __UCLIBC__ */
+#endif /* __UCLIBC__ || __NetBSD__ */
 
 #define MAX_LINEAR_DB_SCALE	24
 
