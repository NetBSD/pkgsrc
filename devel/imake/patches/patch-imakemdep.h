$NetBSD: patch-imakemdep.h,v 1.1 2012/02/10 16:33:40 bsiegert Exp $

--- imakemdep.h.orig	Thu Oct 13 18:50:30 2011
+++ imakemdep.h
@@ -318,6 +318,10 @@ in this Software without prior written a
 #   if defined(__FreeBSD__)  || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #    define USE_CC_E
 #   endif
+#   ifdef __MirBSD__
+#    define USE_CC_E
+#    define DEFAULT_CC "mgcc"
+#   endif
 #   if defined(__sgi) && defined(__ANSI_CPP__)
 #    define USE_CC_E
 #   endif
