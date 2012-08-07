$NetBSD: patch-dns.hh,v 1.2 2012/08/07 23:31:03 marino Exp $

Only attempt to define byte order if unset.
Add DragonFly support

--- dns.hh.orig	2012-08-07 23:18:28.526524000 +0000
+++ dns.hh
@@ -176,12 +176,12 @@ enum  {
 #ifdef WIN32
 #define BYTE_ORDER 1
 #define LITTLE_ENDIAN 1
-#elif __FreeBSD__ || __APPLE__
+#elif defined(__FreeBSD__) || defined(__APPLE__) || defined(__DragonFly__)
 #include <machine/endian.h>
 #elif __linux__
 # include <endian.h>
 
-#else  // with thanks to <arpa/nameser.h> 
+#elif !defined(BYTE_ORDER)  // with thanks to <arpa/nameser.h> 
 
 # define LITTLE_ENDIAN   1234    /* least-significant byte first (vax, pc) */
 # define BIG_ENDIAN      4321    /* most-significant byte first (IBM, net) */
