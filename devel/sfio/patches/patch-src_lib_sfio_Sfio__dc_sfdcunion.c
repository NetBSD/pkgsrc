$NetBSD: patch-src_lib_sfio_Sfio__dc_sfdcunion.c,v 1.1 2011/12/19 14:19:43 wiz Exp $

- use standard C

--- src/lib/sfio/Sfio_dc/sfdcunion.c.orig	1998-03-19 15:04:05.000000000 +0000
+++ src/lib/sfio/Sfio_dc/sfdcunion.c
@@ -124,9 +124,9 @@ Sfdisc_t*      disc;
 
 /* on close, remove the discipline */
 #if __STD_C
-static unexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
+static int unexcept(Sfio_t* f, int type, Void_t* data, Sfdisc_t* disc)
 #else
-static unexcept(f,type,data,disc)
+static int unexcept(f,type,data,disc)
 Sfio_t*		f;
 int		type;
 Void_t*		data;
