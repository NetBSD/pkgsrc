$NetBSD: patch-ckcpro.w,v 1.1 2019/04/11 02:21:09 mrg Exp $

dest is an int.
ffc and calibrate are CK_OFF_Ts.

--- ckcpro.w.orig	2011-06-07 11:39:21.000000000 -0700
+++ ckcpro.w	2019-04-10 19:15:37.736900735 -0700
@@ -151,8 +151,9 @@
   extern int quiet, tsecs, parity, backgrd, nakstate, atcapu, wslotn, winlo;
   extern int wslots, success, xitsta, rprintf, discard, cdtimo, keep, fdispla;
   extern int timef, stdinf, rscapu, sendmode, epktflg, epktrcvd, epktsent;
-  extern int binary, fncnv;
-  extern long speed, ffc, crc16, calibrate, dest;
+  extern int binary, fncnv, dest;
+  extern CK_OFF_T ffc, calibrate;
+  extern long speed, crc16;
 #ifdef COMMENT
   extern char *TYPCMD, *DIRCMD, *DIRCM2;
 #endif /* COMMENT */
