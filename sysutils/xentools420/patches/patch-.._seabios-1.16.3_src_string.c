$NetBSD: patch-.._seabios-1.16.3_src_string.c,v 1.1 2025/08/22 09:00:12 bouyer Exp $

when the code is compiled -fwhole-program, memcpy() will be ommitted by gcc
because nothing in the file references it. Later the link fails with
undefined references to memcpy().
Force the inclusion with (externally_visible) attribute

--- ../seabios-1.16.3/src/string.c.orig	2021-04-17 22:32:25.409876075 +0200
+++ ../seabios-1.16.3/src/string.c	2021-04-17 22:32:39.873615679 +0200
@@ -149,7 +149,7 @@
         memcpy(d_fl, s_fl, len);
 }
 
-void *
+__attribute__((externally_visible)) void *
 #undef memcpy
 memcpy(void *d1, const void *s1, size_t len)
 #if MODESEGMENT == 0
