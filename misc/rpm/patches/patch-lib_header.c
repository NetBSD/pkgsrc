$NetBSD: patch-lib_header.c,v 1.2 2015/03/15 05:34:56 ryoon Exp $

* Detect htonll in configure script.

--- lib/header.c.orig	2014-06-30 08:47:13.000000000 +0000
+++ lib/header.c
@@ -108,6 +108,7 @@ static const size_t headerMaxbytes = (32
 #define	ENTRY_IN_REGION(_e)	((_e)->info.offset < 0)
 
 /* Convert a 64bit value to network byte order. */
+#if !defined(HAVE_HTONLL)
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
