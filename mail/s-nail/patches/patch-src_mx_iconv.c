$NetBSD: patch-src_mx_iconv.c,v 1.1 2026/04/12 02:30:03 ktnb Exp $

Fixed iconv for NetBSD 11

--- src/mx/iconv.c.orig	2026-04-12 02:25:44.693135429 +0000
+++ src/mx/iconv.c
@@ -167,7 +167,7 @@ n_iconv_reset(iconv_t cd){
 /* Citrus project? */
 # if defined _ICONV_H_ && defined __ICONV_F_HIDE_INVALID
   /* DragonFly 3.2.1 is special TODO newer DragonFly too, but different */
-#  if su_OS_DRAGONFLY
+#  if su_OS_DRAGONFLY || su_OS_NETBSD
 #   define a_X(X) S(char** __restrict__,S(void*,UNCONST(char*,X)))
 #  else
 #   define a_X(X) S(char const**,S(void*,UNCONST(char*,X)))
