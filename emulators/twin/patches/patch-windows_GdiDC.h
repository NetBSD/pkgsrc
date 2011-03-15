$NetBSD: patch-windows_GdiDC.h,v 1.1 2011/03/15 11:30:05 obache Exp $

* used as static variables in graphics/GdiDC.c and not refered anywhere else.

--- windows/GdiDC.h.orig	1999-11-16 06:35:55.000000000 +0000
+++ windows/GdiDC.h
@@ -133,9 +133,6 @@ typedef struct tagDCCACHE
     DCINFO *lpDC;
 } DCCACHE;
 
-extern DCCACHE *TWIN_DCCache;
-extern int TWIN_DCCacheSize;
-
 #define	GETHDC32	GETDCINFO
 #define	GETHDC16(h32)	(HDC)((h32)->ObjHead.hObj)
 
