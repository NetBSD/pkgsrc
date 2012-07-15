$NetBSD: patch-coda-src_venus_venusrecov.cc,v 1.1 2012/07/15 17:39:17 marino Exp $

--- coda-src/venus/venusrecov.cc.orig	2008-10-06 16:52:18.000000000 +0000
+++ coda-src/venus/venusrecov.cc
@@ -99,6 +99,7 @@ unsigned long MAXTS = UNSET_MAXTS;
 
 #if defined(NetBSD1_3) || defined(__NetBSD_Version__) || defined(__OpenBSD__) \
  || defined(__linux__) || defined(__CYGWIN32__) || defined(__FreeBSD_version)  \
+ || defined(__DragonFly__) \
  || (defined(__APPLE__) && defined(__MACH__))
 static const char *VM_RVMADDR = (char *)0x50000000;
 
