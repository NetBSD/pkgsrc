$NetBSD: patch-gutils_giomime.c,v 1.1 2012/11/23 20:49:04 adam Exp $

Fix OS X headers.

--- gutils/giomime.c.orig	2012-11-22 16:44:08.000000000 +0000
+++ gutils/giomime.c
@@ -65,7 +65,7 @@ unichar_t fontpcf[] = { 'a','p','p','l',
 unichar_t fontsnf[] = { 'a','p','p','l','i','c','a','t','i','o','n','/','x','-','f','o','n','t','-','s','n','f', '\0' };
 
 #ifdef __Mac
-#include </Developer/Headers/FlatCarbon/Files.h>
+#include <Carbon/Carbon.h>
 #define CHR(ch1,ch2,ch3,ch4) (((ch1)<<24)|((ch2)<<16)|((ch3)<<8)|(ch4))
 
 unichar_t *_GioMacMime(const char *path) {
