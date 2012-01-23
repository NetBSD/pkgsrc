$NetBSD: patch-src_core_spatialite_spatialite.c,v 1.1 2012/01/23 08:58:00 adam Exp $

Fix types.

--- src/core/spatialite/spatialite.c.orig	2011-06-07 07:44:51.000000000 +0000
+++ src/core/spatialite/spatialite.c
@@ -57583,11 +57583,11 @@ Parse (void *yyp,		/* The parser */
 
 /* #include <inttypes.h> */
 typedef int8_t flex_int8_t;
-typedef uint8_t flex_uint8_t;
+typedef u_int8_t flex_uint8_t;
 typedef int16_t flex_int16_t;
-typedef uint16_t flex_uint16_t;
+typedef u_int16_t flex_uint16_t;
 typedef int32_t flex_int32_t;
-typedef uint32_t flex_uint32_t;
+typedef u_int32_t flex_uint32_t;
 #else
 typedef signed char flex_int8_t;
 typedef short int flex_int16_t;
