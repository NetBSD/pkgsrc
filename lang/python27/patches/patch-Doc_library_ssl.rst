$NetBSD: patch-Doc_library_ssl.rst,v 1.1 2015/04/24 03:01:36 rodent Exp $

Fix build with LibreSSL.

--- Doc/library/ssl.rst.orig	2014-12-10 15:59:29.000000000 +0000
+++ Doc/library/ssl.rst
@@ -300,6 +300,8 @@ Random generation
    See http://egd.sourceforge.net/ or http://prngd.sourceforge.net/ for sources
    of entropy-gathering daemons.
 
+   Availability: not available with LibreSSL.
+
 .. function:: RAND_add(bytes, entropy)
 
    Mixes the given *bytes* into the SSL pseudo-random number generator.  The
