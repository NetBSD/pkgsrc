$NetBSD: patch-caca_caca.h,v 1.1 2014/02/23 00:35:32 schmonz Exp $

Build with clang on Darwin, from upstream: http://caca.zoy.org/ticket/90

--- caca/caca.h.orig	2012-04-06 20:21:48.000000000 +0000
+++ caca/caca.h
@@ -683,7 +683,7 @@ typedef struct cucul_buffer cucul_buffer
 #       define CACA_DEPRECATED
 #   endif
 
-#   if defined __GNUC__ && __GNUC__ > 3
+#   if !defined __APPLE__ && defined __GNUC__ && __GNUC__ > 3
 #       define CACA_ALIAS(x) __attribute__ ((weak, alias(#x)))
 #   else
 #       define CACA_ALIAS(x)
