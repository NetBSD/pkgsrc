$NetBSD: patch-lib_header.c,v 1.4 2023/05/15 13:52:38 jperkin Exp $

* Detect htonll in configure script.

--- lib/header.c.orig	2017-02-16 09:54:14.797025194 +0000
+++ lib/header.c
@@ -108,6 +108,7 @@ static const size_t headerMaxbytes = (32
 #define	ENTRY_IN_REGION(_e)	((_e)->info.offset < 0)
 
 /* Convert a 64bit value to network byte order. */
+#if !defined(htonll) && !defined(__sun)
 RPM_GNUC_CONST
 static uint64_t htonll(uint64_t n)
 {
@@ -119,6 +120,7 @@ static uint64_t htonll(uint64_t n)
 #endif
     return n;
 }
+#endif
 
 Header headerLink(Header h)
 {
