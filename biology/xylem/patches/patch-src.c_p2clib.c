$NetBSD: patch-src.c_p2clib.c,v 1.1 2018/09/29 12:49:55 tnn Exp $

Add explicit prototype.

--- src.c/p2clib.c.orig	1996-05-03 16:31:13.000000000 +0000
+++ src.c/p2clib.c
@@ -64,6 +64,7 @@ long x;
 
 
 #ifdef __STDC__
+Anyptr my_memcpy(Anyptr d, Const Anyptr s, size_t n);
 Anyptr my_memmove(Anyptr d, Const Anyptr s, size_t n)
 #else
 Anyptr my_memmove(d, s, n)
