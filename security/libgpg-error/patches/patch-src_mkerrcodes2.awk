$NetBSD: patch-src_mkerrcodes2.awk,v 1.1 2019/10/08 06:36:13 triaxx Exp $

Prepare for Gawk 5.0.
Don't escape # in regexp.
https://github.com/gpg/libgpg-error/commit/7865041

--- src/mkerrcodes2.awk.orig	2013-03-15 19:24:25.000000000 +0000
+++ src/mkerrcodes2.awk
@@ -91,7 +91,7 @@ header {
 }
 
 !header {
-  sub (/\#.+/, "");
+  sub (/#.+/, "");
   sub (/[ 	]+$/, ""); # Strip trailing space and tab characters.
 
   if (/^$/)
