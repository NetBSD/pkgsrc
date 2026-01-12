$NetBSD: patch-nss_lib_dbm_include_mcom__db.h,v 1.1 2026/01/12 14:12:35 prlw1 Exp $

Cargo cult the test for operating systems rather
than test for endian.h

--- ./nss/lib/dbm/include/mcom_db.h.orig	2026-01-08 11:14:43.000000000 +0000
+++ ./nss/lib/dbm/include/mcom_db.h
@@ -60,7 +60,7 @@ typedef PRUint32 uint32;
 #include <sys/byteorder.h>
 #endif
 
-#if defined(__linux)
+#if defined(__linux) || defined(__NetBSD__)
 #include <endian.h>
 #ifndef BYTE_ORDER
 #define BYTE_ORDER __BYTE_ORDER
