$NetBSD: patch-src_fcobjshash.h,v 1.2 2017/06/20 11:42:09 wiz Exp $

Fix signature for FC_GPERF_SIZE_T=size_t systems.
https://bugs.freedesktop.org/show_bug.cgi?id=101514

--- src/fcobjshash.h.orig	2017-02-22 12:37:50.000000000 +0000
+++ src/fcobjshash.h
@@ -47,7 +47,7 @@ inline
 #endif
 #endif
 static unsigned int
-FcObjectTypeHash (register const char *str, register unsigned int len)
+FcObjectTypeHash (register const char *str, register FC_GPERF_SIZE_T len)
 {
   static const unsigned char asso_values[] =
     {
@@ -191,7 +191,7 @@ __attribute__ ((__gnu_inline__))
 #endif
 #endif
 const struct FcObjectTypeInfo *
-FcObjectTypeLookup (register const char *str, register unsigned int len)
+FcObjectTypeLookup (register const char *str, register FC_GPERF_SIZE_T len)
 {
   enum
     {
