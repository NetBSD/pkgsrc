$NetBSD: patch-arj__proc.c,v 1.1 2022/01/08 14:43:09 tnn Exp $

debian/001_arches_align.patch
Description: Correct build failure on ia64 due to unaligned memory access.
Author: Guillem Jover <guillem@debian.org>
Origin: vendor
Forwarded: no
Last-Update: 2008-06-16


debian/003_64_bit_clean.patch
Description: Make code 64-bit clean.
Author: Guillem Jover <guillem@debian.org>
Origin: vendor
Bug-Debian: https://bugs.debian.org/339815
Forwarded: no
Last-Update: 2005-11-24

debian/self_integrity_64bit.patch
Description: Fix arj self-integrity check on 64-bit systems
Author: B Watson <yalhcru@gmail.com>
Origin: other, http://slackbuilds.org/cgit/slackbuilds/tree/system/arj/patches/SBo_integrity_64bit.patch
Forwarded: no
Reviewed-By: Guillem Jover <guillem@debian.org>
Last-Update: 2014-08-06

--- arj_proc.c.orig	2022-01-08 14:35:06.610901643 +0000
+++ arj_proc.c
@@ -586,7 +586,7 @@ int search_for_extension(char *name, cha
 /* Returns the exact amount of data that could be safely written to the
    destination volume */
 
-unsigned long get_volfree(unsigned int increment)
+unsigned long get_volfree(unsigned long increment)
 {
  unsigned long pvol;
  unsigned int arjsec_overhead;
@@ -606,7 +606,7 @@ unsigned long get_volfree(unsigned int i
  remain=volume_limit-ftell(aostream)-pvol-(long)arjsec_overhead-
         (long)out_bytes-(long)cpos-(long)ext_voldata-
         MULTIVOLUME_RESERVE-t_volume_offset;
- return((unsigned long)min(remain, (unsigned long)increment));
+ return((unsigned long)min(remain, increment));
 }
 
 /* Performs various checks when multivolume data is packed to predict an
@@ -2467,14 +2467,14 @@ static int get_str_from_jq()
     *tsptr='\0';
   endptr=tsptr;
   tsptr=sptr;
-  while((unsigned int)tsptr<(unsigned int)endptr&&patterns<SEARCH_STR_MAX)
+  while((intptr_t)tsptr<(intptr_t)endptr&&patterns<SEARCH_STR_MAX)
   {
    while(*tsptr=='\0')
     tsptr++;
-   if((unsigned int)tsptr<(unsigned int)endptr)
+   if((intptr_t)tsptr<(intptr_t)endptr)
    {
     search_str[patterns++]=tsptr;
-    while(*tsptr!='\0'&&(unsigned int)tsptr<(unsigned int)endptr)
+    while(*tsptr!='\0'&&(intptr_t)tsptr<(intptr_t)endptr)
      tsptr++;
    }
   }
@@ -2899,12 +2899,12 @@ char *ltrim(char *str)
 }
 #endif
 
-#if defined(WORDS_BIGENDIAN)&&!defined(ARJDISP)&&!defined(REGISTER)
+#if (defined(WORDS_BIGENDIAN) || defined(ALIGN_POINTERS)) && !defined(ARJDISP) && !defined(REGISTER)
 /* Model-independent routine to get 2 bytes from far RAM */
 
-unsigned int mget_word(char FAR *p)
+uint16_t mget_word(char FAR *p)
 {
- unsigned int b0, b1;
+ uint16_t b0, b1;
 
  b0=mget_byte(p);
  b1=mget_byte(p+1);
@@ -2913,9 +2913,9 @@ unsigned int mget_word(char FAR *p)
 
 /* Model-independent routine to get 4 bytes from far RAM */
 
-unsigned long mget_dword(char FAR *p)
+uint32_t mget_dword(char FAR *p)
 {
- unsigned long w0, w1;
+ uint32_t w0, w1;
 
  w0=mget_word(p);
  w1=mget_word(p+2);
@@ -2924,7 +2924,7 @@ unsigned long mget_dword(char FAR *p)
 
 /* Model-independent routine to store 2 bytes in far RAM */
 
-void mput_word(unsigned int w, char FAR *p)
+void mput_word(uint16_t w, char FAR *p)
 {
  mput_byte(w&0xFF, p);
  mput_byte(w>>8  , p+1);
@@ -2932,7 +2932,7 @@ void mput_word(unsigned int w, char FAR 
 
 /* Model-independent routine to store 4 bytes in far RAM */
 
-void mput_dword(unsigned long d, char FAR *p)
+void mput_dword(uint32_t d, char FAR *p)
 {
  mput_word(d&0xFFFF, p);
  mput_word(d>>16   , p+2);
