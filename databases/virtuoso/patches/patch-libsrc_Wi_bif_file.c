$NetBSD: patch-libsrc_Wi_bif_file.c,v 1.1 2013/04/13 13:16:02 jaapb Exp $

Redefine non-existent functions
--- libsrc/Wi/bif_file.c.orig	2012-08-01 20:54:31.000000000 +0000
+++ libsrc/Wi/bif_file.c
@@ -6195,7 +6195,7 @@ signal_error:
 }
 
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #define fseeko64 fseeko
 #define ftello64 ftello
 #define fopen64  fopen
