$NetBSD: patch-libpurple_protocols_gg_lib_libgadu.h,v 1.1 2012/03/09 11:45:01 fhajny Exp $

Make the SunOS condition a little more generic.
--- libpurple/protocols/gg/lib/libgadu.h.orig	2011-03-11 02:20:27.000000000 +0000
+++ libpurple/protocols/gg/lib/libgadu.h
@@ -117,7 +117,7 @@ typedef unsigned char   uint8_t;
 typedef unsigned short uint16_t;
 typedef unsigned int   uint32_t;
 
-#if !defined(__CYGWIN__) && !defined(__SunOS) && !defined(_INCLUDE_HPUX_SOURCE)
+#if !defined(__CYGWIN__) && !defined(__sun) && !defined(_INCLUDE_HPUX_SOURCE)
 #define __int8_t_defined
 typedef   signed char    int8_t;
 typedef   signed short  int16_t;
