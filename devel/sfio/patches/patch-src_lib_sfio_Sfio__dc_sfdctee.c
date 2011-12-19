$NetBSD: patch-src_lib_sfio_Sfio__dc_sfdctee.c,v 1.1 2011/12/19 14:19:43 wiz Exp $

- use standard C

--- src/lib/sfio/Sfio_dc/sfdctee.c.orig	1999-06-01 15:22:34.000000000 +0000
+++ src/lib/sfio/Sfio_dc/sfdctee.c
@@ -37,9 +37,9 @@ Sfdisc_t*	disc;	/* the tee discipline */
 
 /* on close, remove the discipline */
 #if __STD_C
-static teeexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
+static int teeexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
 #else
-static teeexcept(f,type,data,disc)
+static int teeexcept(f,type,data,disc)
 Sfio_t*		f;
 int		type;
 Void_t*		data;
