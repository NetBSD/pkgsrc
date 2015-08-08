$NetBSD: patch-Xvnc_programs_Xserver_cfb_cfbrrop.h,v 1.1 2015/08/08 23:37:56 mrg Exp $

RROP_UNROLL_CASE63() wants a RROP_UNROLL_CASE32 that doesn't exist.


--- Xvnc/programs/Xserver/cfb/cfbrrop.h.orig	2000-06-11 22:00:51.000000000 +1000
+++ Xvnc/programs/Xserver/cfb/cfbrrop.h	2015-08-09 04:58:28.000000000 +1000
@@ -275,6 +275,7 @@
 #define RROP_UNROLL_CASE15(p)	RROP_UNROLL_CASE8(p,8) RROP_UNROLL_CASE7(p)
 #define RROP_UNROLL_CASE31(p)	RROP_UNROLL_CASE16(p,16) RROP_UNROLL_CASE15(p)
 #ifdef LONG64
+#define RROP_UNROLL_CASE32(p,i)   RROP_UNROLL_CASE16(p,(i)+16) RROP_UNROLL_CASE16(p,i)
 #define RROP_UNROLL_CASE63(p)	RROP_UNROLL_CASE32(p,32) RROP_UNROLL_CASE31(p)
 #endif /* LONG64 */
 
