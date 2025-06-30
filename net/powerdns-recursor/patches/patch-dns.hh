$NetBSD: patch-dns.hh,v 1.4 2025/06/30 11:06:46 jperkin Exp $

Only attempt to define byte order if unset.

--- dns.hh.orig	2024-09-17 08:11:58.000000000 +0000
+++ dns.hh
@@ -120,7 +120,7 @@ static_assert(sizeof(EDNS0Record) == 4,
 #elif __linux__ || __GNU__
 # include <endian.h>
 
-#else  // with thanks to <arpa/nameser.h> 
+#elif !defined(BYTE_ORDER)  // with thanks to <arpa/nameser.h> 
 
 # define LITTLE_ENDIAN   1234    /* least-significant byte first (vax, pc) */
 # define BIG_ENDIAN      4321    /* most-significant byte first (IBM, net) */
