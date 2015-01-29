$NetBSD: patch-machine.h,v 1.2 2015/01/29 21:30:35 joerg Exp $

* Force the use of -ltermcap and let BUILDLINK_TRANSFORM sort out the right
 library to use.
* Install *.tbl files to ${PREFIX}/share/fd. 

--- machine.h.orig	2014-05-05 15:00:00.000000000 +0000
+++ machine.h
@@ -638,9 +638,11 @@ typedef long	off_t;
 #define	CODEEUC
 #define	BSDINSTALL
 #define	TARUSESPACE
+#define	TERMCAPLIB		"-ltermcap"
 #define	REGEXPLIB		"-lcompat"
 #define	DECLSIGLIST
 #define	DECLERRLIST
+#define	USEDATADIR
 #define	USELEAPCNT
 #define	USEFFSTYPE
 #define	USERE_COMP
@@ -1210,7 +1212,7 @@ typedef long	off_t;
 #define	USEGETGROUPS
 #endif
 
-#if	(!defined (__GNUC__) || defined (__clang__)) \
+#if	(!defined (__GNUC__) && !defined (__clang__)) \
 && !defined (__attribute__)
 #define	__attribute__(x)
 #endif
