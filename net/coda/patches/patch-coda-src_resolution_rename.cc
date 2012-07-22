$NetBSD: patch-coda-src_resolution_rename.cc,v 1.2 2012/07/22 03:20:03 dholland Exp $

Make sure MAXNAMLEN is defined by filling in from NAME_MAX, which is
standard. (It isn't clear why this expects MAXNAMLEN to be defined
without including sys/param.h, or on what platforms it built
succesfully that way. It maybe should be using CODA_MAXNAMLEN instead;
I can't tell for sure.)

--- coda-src/resolution/rename.cc.orig	2006-09-19 17:35:48.000000000 +0000
+++ coda-src/resolution/rename.cc
@@ -21,6 +21,7 @@ extern "C" {
 #endif
 
 #include <stdio.h>
+#include <limits.h>
 #include <rpc2/rpc2.h>
 #ifndef __CYGWIN32__
 #include <dirent.h>
@@ -51,6 +52,10 @@ extern "C" {
 #include "rsle.h"
 #include "resstats.h"
 
+#ifndef MAXNAMLEN
+#define MAXNAMLEN NAME_MAX
+#endif
+
 static void AddToIncList(dlist *, dlist *, Volume *, ViceFid *, int =0);
 static int CheckResolveRenameSemantics(rsle *, Volume *, ViceFid *, dlist *, vle **, vle **, vle **, 
 					vle **,olist *, dlist *, dlist *, int *);
