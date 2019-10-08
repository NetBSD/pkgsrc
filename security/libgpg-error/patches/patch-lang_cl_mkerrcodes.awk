$NetBSD: patch-lang_cl_mkerrcodes.awk,v 1.1 2019/10/08 06:36:13 triaxx Exp $

Prepare for Gawk 5.0.
Don't escape # in regexp.
https://github.com/gpg/libgpg-error/commit/7865041

--- lang/cl/mkerrcodes.awk.orig	2013-03-15 19:24:25.000000000 +0000
+++ lang/cl/mkerrcodes.awk
@@ -122,7 +122,7 @@ header {
 }
 
 !header {
-  sub (/\#.+/, "");
+  sub (/#.+/, "");
   sub (/[ 	]+$/, ""); # Strip trailing space and tab characters.
 
   if (/^$/)
