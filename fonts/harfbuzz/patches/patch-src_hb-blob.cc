$NetBSD: patch-src_hb-blob.cc,v 1.1 2018/10/29 13:55:14 abs Exp $

Quoting the URL given in the source:

  The POSIX standard states that a strictly conforming application
  "for the C programming language, shall define _POSIX_C_SOURCE to
  be 200112L before any header is included."

Asserting this for only one file out of an application is not defined,
and the standards also explicitly do not apply to c++.

Its quite possible that some operating systems need _POSIX_C_SOURCE
set to build this file, but its not a general solution, and lets
not do it on NetBSD where is interacts badly with at least gcc-6.4
7.3 and 8.2 on NetBSD-8/amd64

--- src/hb-blob.cc.orig	2018-06-05 22:13:36.000000000 +0000
+++ src/hb-blob.cc
@@ -26,7 +26,7 @@
  */
 
 /* http://www.oracle.com/technetwork/articles/servers-storage-dev/standardheaderfiles-453865.html */
-#ifndef _POSIX_C_SOURCE
+#if !defined(_POSIX_C_SOURCE) && !defined(__NetBSD__)
 #define _POSIX_C_SOURCE 200809L
 #endif
 
