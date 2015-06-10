$NetBSD: patch-dns.hh,v 1.3 2015/06/10 14:22:29 fhajny Exp $

Only attempt to define byte order if unset.

--- dns.hh.orig	2015-04-21 13:02:57.000000000 +0000
+++ dns.hh
@@ -149,7 +149,7 @@ struct EDNS0Record
 #elif __linux__ || __GNU__
 # include <endian.h>
 
-#else  // with thanks to <arpa/nameser.h> 
+#elif !defined(BYTE_ORDER)  // with thanks to <arpa/nameser.h> 
 
 # define LITTLE_ENDIAN   1234    /* least-significant byte first (vax, pc) */
 # define BIG_ENDIAN      4321    /* most-significant byte first (IBM, net) */
