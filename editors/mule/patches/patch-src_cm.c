$NetBSD: patch-src_cm.c,v 1.1 2013/04/21 15:39:59 joerg Exp $

--- src/cm.c.orig	1994-10-21 04:19:53.000000000 +0000
+++ src/cm.c
@@ -282,7 +282,7 @@ losecursor ()
 #define	USELL	2
 #define	USECR	3
 
-cmgoto (row, col)
+void cmgoto (int row, int col)
 {
     int     homecost,
             crcost,
