$NetBSD: patch-.._seabios-rel-1.12.1_src_string.c,v 1.1 2021/02/04 23:51:51 bouyer Exp $

when the code is compiled -fwhole-program, memcpy() will be ommitted by gcc
because nothing in the file references it. Later the link fails with
undefined references to memcpy().
Force the inclusion with (externally_visible) attribute

--- ../seabios-rel-1.12.1/src/string.c.orig	2021-02-04 23:06:35.686612339 +0100
+++ ../seabios-rel-1.12.1/src/string.c	2021-02-04 23:03:33.884883498 +0100
@@ -149,7 +149,7 @@
         memcpy(d_fl, s_fl, len);
 }
 
-void *
+__attribute__((externally_visible)) void *
 #undef memcpy
 memcpy(void *d1, const void *s1, size_t len)
 #if MODESEGMENT == 0
