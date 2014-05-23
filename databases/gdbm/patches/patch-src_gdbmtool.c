$NetBSD: patch-src_gdbmtool.c,v 1.1 2014/05/23 20:49:37 wiz Exp $

Avoid conflict with sys/syslimits.h.

--- src/gdbmtool.c.orig	2013-05-21 19:48:31.000000000 +0000
+++ src/gdbmtool.c
@@ -1347,7 +1347,7 @@ coerce_s2d (struct gdbmarg *arg, struct 
 
 #define coerce_fail NULL
 
-coerce_type_t coerce_tab[ARG_MAX][ARG_MAX] = {
+coerce_type_t coerce_tab[GDBM_ARG_MAX][GDBM_ARG_MAX] = {
   /*             s            d            k */
   /* s */  { coerce_ref,  coerce_fail, coerce_fail },
   /* d */  { coerce_s2d,  coerce_ref,  coerce_k2d }, 
