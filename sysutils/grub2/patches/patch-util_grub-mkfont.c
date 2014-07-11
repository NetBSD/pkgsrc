$NetBSD: patch-util_grub-mkfont.c,v 1.1 2014/07/11 10:58:43 jperkin Exp $

Fix ftsynth.h include.

--- util/grub-mkfont.c.orig	2012-03-10 12:17:57.000000000 +0000
+++ util/grub-mkfont.c
@@ -39,7 +39,7 @@
 #include FT_FREETYPE_H
 #include FT_TRUETYPE_TAGS_H
 #include FT_TRUETYPE_TABLES_H
-#include <freetype/ftsynth.h>
+#include FT_SYNTHESIS_H
 
 #undef __FTERRORS_H__
 #define FT_ERROR_START_LIST   const char *ft_errmsgs[] = { 
