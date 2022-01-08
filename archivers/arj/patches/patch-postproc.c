$NetBSD: patch-postproc.c,v 1.1 2022/01/08 14:43:09 tnn Exp $

debian/self_integrity_64bit.patch
Description: Fix arj self-integrity check on 64-bit systems
Author: B Watson <yalhcru@gmail.com>
Origin: other, http://slackbuilds.org/cgit/slackbuilds/tree/system/arj/patches/SBo_integrity_64bit.patch
Forwarded: no
Reviewed-By: Guillem Jover <guillem@debian.org>
Last-Update: 2014-08-06

--- postproc.c.orig	2003-06-22 11:12:28.000000000 +0000
+++ postproc.c
@@ -6,6 +6,7 @@
  *
  */
 
+#include <stdint.h>
 #include "arj.h"
 
 /* Operations */
@@ -37,8 +38,9 @@ static unsigned short self_check[]={0x90
 
 static char buf[PROC_BLOCK_SIZE];
 
-static void _fput_dword(const unsigned long l, FILE *stream)
+static void _fput_dword(const unsigned long w, FILE *stream)
 {
+ uint32_t l = (uint32_t)w;
 #ifdef WORDS_BIGENDIAN
  fputc(l    ,stream);
  fputc(l>>8 ,stream);
