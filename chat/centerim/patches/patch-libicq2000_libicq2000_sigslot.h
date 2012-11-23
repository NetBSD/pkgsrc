$NetBSD: patch-libicq2000_libicq2000_sigslot.h,v 1.1 2012/11/23 20:48:05 marino Exp $

--- libicq2000/libicq2000/sigslot.h.orig	2009-08-27 11:16:41.000000000 +0000
+++ libicq2000/libicq2000/sigslot.h
@@ -82,6 +82,7 @@
 #ifndef SIGSLOT_H__
 #define SIGSLOT_H__
 
+#include <unistd.h>
 #include <set>
 #include <list>
 
