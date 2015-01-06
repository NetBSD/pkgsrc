$NetBSD: patch-machine.h,v 1.1 2015/01/06 11:24:58 ryoon Exp $

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
