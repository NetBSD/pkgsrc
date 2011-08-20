$NetBSD: patch-src-slirp-slirp.h,v 1.1 2011/08/20 15:30:36 joerg Exp $

--- src/slirp/slirp.h.orig	2011-08-20 13:13:12.000000000 +0000
+++ src/slirp/slirp.h
@@ -288,8 +288,8 @@ extern int do_echo;
 # define insque_32 insque
 # define remque_32 remque
 #else
- inline void insque_32 _P((void *, void *));
- inline void remque_32 _P((void *));
+ void insque_32 _P((void *, void *));
+ void remque_32 _P((void *));
 #endif
 
 #ifndef _WIN32
