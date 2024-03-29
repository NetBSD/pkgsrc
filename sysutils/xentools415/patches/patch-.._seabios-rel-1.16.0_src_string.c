$NetBSD: patch-.._seabios-rel-1.16.0_src_string.c,v 1.1 2023/08/24 10:27:09 bouyer Exp $

when the code is compiled -fwhole-program, memcpy() will be ommitted by gcc
because nothing in the file references it. Later the link fails with
undefined references to memcpy().
Force the inclusion with (externally_visible) attribute

--- ../seabios-rel-1.16.0/src/string.c.orig	2021-04-17 22:32:25.409876075 +0200
+++ ../seabios-rel-1.16.0/src/string.c	2021-04-17 22:32:39.873615679 +0200
@@ -149,7 +149,7 @@
         memcpy(d_fl, s_fl, len);
 }
 
-void *
+__attribute__((externally_visible)) void *
 #undef memcpy
 memcpy(void *d1, const void *s1, size_t len)
 #if MODESEGMENT == 0
