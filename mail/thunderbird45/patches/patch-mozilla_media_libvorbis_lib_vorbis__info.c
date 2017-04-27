$NetBSD: patch-mozilla_media_libvorbis_lib_vorbis__info.c,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/media/libvorbis/lib/vorbis_info.c.orig	2016-04-07 21:33:21.000000000 +0000
+++ mozilla/media/libvorbis/lib/vorbis_info.c
@@ -77,7 +77,7 @@ void vorbis_comment_add_tag(vorbis_comme
 static int tagcompare(const char *s1, const char *s2, int n){
   int c=0;
   while(c < n){
-    if(toupper(s1[c]) != toupper(s2[c]))
+    if(toupper((unsigned char)s1[c]) != toupper((unsigned char)s2[c]))
       return !0;
     c++;
   }
