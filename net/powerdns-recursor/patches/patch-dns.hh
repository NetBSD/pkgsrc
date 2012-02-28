$NetBSD: patch-dns.hh,v 1.1 2012/02/28 10:49:28 roy Exp $

Only attempt to define byte order if unset.

--- dns.hh.orig	2010-09-21 16:22:09.000000000 +0000
+++ dns.hh
@@ -181,7 +181,7 @@ enum  {
 #elif __linux__
 # include <endian.h>
 
-#else  // with thanks to <arpa/nameser.h> 
+#elif !defined(BYTE_ORDER)  // with thanks to <arpa/nameser.h> 
 
 # define LITTLE_ENDIAN   1234    /* least-significant byte first (vax, pc) */
 # define BIG_ENDIAN      4321    /* most-significant byte first (IBM, net) */
