$NetBSD: patch-libtme_misc.c,v 1.1 2020/08/13 05:59:52 tsutsui Exp $

- Remove garbage.

--- libtme/misc.c.orig	2010-06-05 19:02:38.000000000 +0000
+++ libtme/misc.c
@@ -430,7 +430,7 @@ tme_misc_cycles_per_ms(void)
 union tme_value64
 tme_misc_cycles(void)
 {
-#ifdef TME_HAVE_INT64_T */
+#ifdef TME_HAVE_INT64_T
   struct timeval now;
   tme_uint64_t cycles;
   union tme_value64 value;
