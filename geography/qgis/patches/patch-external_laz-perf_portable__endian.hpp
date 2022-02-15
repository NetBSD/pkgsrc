$NetBSD: patch-external_laz-perf_portable__endian.hpp,v 1.1 2022/02/15 12:59:21 gdt Exp $

Fix laz-perf bug of thinking NetBSD is like DragonFly, when it is
straightforwardly like OpenBSD and FreeBSD.

Reported upstream at https://github.com/hobu/laz-perf/issues/115

--- external/laz-perf/portable_endian.hpp.orig	2022-01-14 12:06:34.000000000 +0000
+++ external/laz-perf/portable_endian.hpp
@@ -43,11 +43,11 @@
 #   define __PDP_ENDIAN    PDP_ENDIAN
 **/
 
-#elif defined(__OpenBSD__)|| defined(__FreeBSD__) 
+#elif defined(__OpenBSD__)|| defined(__FreeBSD__) || defined(__NetBSD__)
 
 #   include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__DragonFly__)
+#elif defined(__DragonFly__)
 
 #   define be16toh betoh16
 #   define le16toh letoh16
