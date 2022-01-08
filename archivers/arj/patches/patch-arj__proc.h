$NetBSD: patch-arj__proc.h,v 1.1 2022/01/08 14:43:09 tnn Exp $

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

--- arj_proc.h.orig	2022-01-08 14:35:15.711534423 +0000
+++ arj_proc.h
@@ -8,15 +8,17 @@
 #ifndef ARJ_PROC_INCLUDED
 #define ARJ_PROC_INCLUDED
 
+#include <stdint.h>
+
 /* Helper macros */
 
-#define mget_byte(p) (*(unsigned char FAR *)(p)&0xFF)
-#define mput_byte(c, p) *(unsigned char FAR *)(p)=(unsigned char)(c)
-#ifndef WORDS_BIGENDIAN
-#define mget_word(p) (*(unsigned short *)(p)&0xFFFF)
-#define mput_word(w,p) (*(unsigned short *)(p)=(unsigned short)(w))
-#define mget_dword(p) (*(unsigned long *)(p))
-#define mput_dword(w,p) (*(unsigned long *)(p)=(unsigned long)(w))
+#define mget_byte(p) (*(uint8_t FAR *)(p)&0xFF)
+#define mput_byte(c, p) *(uint8_t FAR *)(p)=(uint8_t)(c)
+#if !defined(ALIGN_POINTERS) && !defined(WORDS_BIGENDIAN)
+#define mget_word(p) (*(uint16_t *)(p)&0xFFFF)
+#define mput_word(w,p) (*(uint16_t *)(p)=(uint16_t)(w))
+#define mget_dword(p) (*(uint32_t *)(p))
+#define mput_dword(w,p) (*(uint32_t *)(p)=(uint32_t)(w))
 #endif
 
 /* Prototypes */
@@ -31,7 +33,7 @@ void copy_bytes(unsigned long nbytes);
 int translate_path(char *name);
 void restart_proc(char *dest);
 int search_for_extension(char *name, char *ext_list);
-unsigned long get_volfree(unsigned int increment);
+unsigned long get_volfree(unsigned long increment);
 unsigned int check_multivolume(unsigned int increment);
 void store();
 void hollow_encode();
@@ -60,11 +62,11 @@ void pack_mem(struct mempack *mempack);
 void unpack_mem(struct mempack *mempack);
 void strip_lf(char *str);
 char *ltrim(char *str);
-#ifdef WORDS_BIGENDIAN
-unsigned int mget_word(char FAR *p);
-unsigned long mget_dword(char FAR *p);
-void mput_word(unsigned int w, char FAR *p);
-void mput_dword(unsigned long d, char FAR *p);
+#if defined(ALIGN_POINTERS) || defined(WORDS_BIGENDIAN)
+uint16_t mget_word(char FAR *p);
+uint32_t mget_dword(char FAR *p);
+void mput_word(uint16_t w, char FAR *p);
+void mput_dword(uint32_t d, char FAR *p);
 #endif
 
 #endif
