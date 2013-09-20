$NetBSD: patch-lib_header.c,v 1.1 2013/09/20 17:26:14 ryoon Exp $

* Detect htonll in configure script.

--- lib/header.c.orig	2013-06-10 15:55:10.000000000 +0000
+++ lib/header.c
@@ -102,6 +102,7 @@ static const size_t headerMaxbytes = (32
 #define	ENTRY_IN_REGION(_e)	((_e)->info.offset < 0)
 
 /* Convert a 64bit value to network byte order. */
+#if !defined(HAVE_HTONLL)
 RPM_GNUC_CONST
 static uint64_t htonll(uint64_t n)
 {
@@ -111,6 +112,7 @@ static uint64_t htonll(uint64_t n)
     i[1] = htonl(b);
     return n;
 }
+#endif
 
 Header headerLink(Header h)
 {
