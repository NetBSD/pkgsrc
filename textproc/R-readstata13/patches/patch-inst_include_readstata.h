$NetBSD: patch-inst_include_readstata.h,v 1.1 2019/09/26 01:18:30 wiz Exp $

fseeko64 only exists on Linux.
off64_t is not used in the code.

--- inst/include/readstata.h.orig	2018-05-26 07:44:32.000000000 +0000
+++ inst/include/readstata.h
@@ -40,8 +40,7 @@ typedef unsigned int uint32_t;
 #include <stdint.h>
 #endif
 
-#ifdef __APPLE__
-#  define off64_t off_t
+#if !defined(__Linux__)
 #  define fseeko64 fseeko
 #endif
 
