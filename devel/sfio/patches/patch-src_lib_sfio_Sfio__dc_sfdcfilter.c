$NetBSD: patch-src_lib_sfio_Sfio__dc_sfdcfilter.c,v 1.1 2011/12/19 14:19:43 wiz Exp $

- use standard C

--- src/lib/sfio/Sfio_dc/sfdcfilter.c.orig	1998-03-19 16:10:25.000000000 +0000
+++ src/lib/sfio/Sfio_dc/sfdcfilter.c
@@ -103,9 +103,9 @@ Sfdisc_t*	disc;
 
 /* on close, remove the discipline */
 #if __STD_C
-static filterexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
+static int filterexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
 #else
-static filterexcept(f,type,data,disc)
+static int filterexcept(f,type,data,disc)
 Sfio_t*		f;
 int		type;
 Void_t*		data;
