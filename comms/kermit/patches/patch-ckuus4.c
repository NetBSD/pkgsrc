$NetBSD: patch-ckuus4.c,v 1.1 2019/04/11 02:21:09 mrg Exp $

Always include errno.h.
crc16 is a long.

--- ckuus4.c.orig	2011-06-24 11:58:10.000000000 -0700
+++ ckuus4.c	2019-04-10 18:25:09.650654615 -0700
@@ -34,8 +34,9 @@
 #include "ck_ssl.h"
 #endif /* CK_SSL */
 
+#include <errno.h>
+
 #ifdef VMS
-#include <errno.h>                      /* For \v(errno) */
 extern char * ckvmserrstr(unsigned long);
 #ifndef OLD_VMS
 #include <lib$routines.h>               /* Not for VAX C 2.4 */
@@ -409,7 +410,9 @@
   npad, pkttim, bigrbsiz, bigsbsiz, keep, atcapr, autopar, bctr, bctu,
   crunched, ckdelay, ebq, ebqflg, pktlog, retrans, rpackets, rptflg, rptq,
   rtimo, spackets, spsiz, spsizf, spsizr, timeouts, fncact, fncnv, urpsiz,
-  wmax, wslotn, wslotr, fdispla, spmax, fnrpath, fnspath, crc16;
+  wmax, wslotn, wslotr, fdispla, spmax, fnrpath, fnspath;
+extern long
+  crc16;
 #endif /* NOXFER */
 
 #ifdef OS2
