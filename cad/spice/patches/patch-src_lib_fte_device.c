$NetBSD: patch-src_lib_fte_device.c,v 1.1 2013/03/02 17:51:49 joerg Exp $

--- src/lib/fte/device.c.orig	2013-03-01 22:48:02.000000000 +0000
+++ src/lib/fte/device.c
@@ -14,6 +14,7 @@ Author: 1986 Wayne A. Christopher, U. C.
 #include "ftedefs.h"
 #include "dgen.h"
 
+static void com_alter_common(wordlist *wl, int do_model);
 static wordlist *devexpand();
 
 /*
@@ -576,9 +577,7 @@ com_altermod(wl)
     com_alter_common(wl, 1);
 }
 
-com_alter_common(wl, do_model)
-    wordlist *wl;
-    int	do_model;
+static void com_alter_common(wordlist *wl, int do_model)
 {
 #ifdef notdef
     struct variable var, *nv, *prev;
