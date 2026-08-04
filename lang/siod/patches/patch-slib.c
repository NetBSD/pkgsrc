$NetBSD: patch-slib.c,v 1.1 2026/08/04 14:59:48 ryoon Exp $

* Fix build with GCC 14.

--- slib.c.orig	2026-08-04 12:33:38.331190317 +0000
+++ slib.c
@@ -169,7 +169,7 @@ void __stdcall process_cla(int argc,char **argv,int wa
 void __stdcall process_cla(int argc,char **argv,int warnflag)
 {int k;
  char *ptr;
- static siod_lib_set = 0;
+ static int siod_lib_set = 0;
 #if !defined(vms)
  if (!siod_lib_set)
    {
