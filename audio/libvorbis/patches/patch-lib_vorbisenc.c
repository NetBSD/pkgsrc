$NetBSD: patch-lib_vorbisenc.c,v 1.1 2018/08/06 13:25:38 snj Exp $

https://gitlab.xiph.org/xiph/vorbis/issues/2335

--- lib/vorbisenc.c.orig	2018-08-06 06:17:42.209959046 -0700
+++ lib/vorbisenc.c	2018-08-06 06:18:01.425700460 -0700
@@ -684,6 +684,7 @@ int vorbis_encode_setup_init(vorbis_info
   highlevel_encode_setup *hi=&ci->hi;
 
   if(ci==NULL)return(OV_EINVAL);
+  if(vi->channels<1||vi->channels>255)return(OV_EINVAL);
   if(!hi->impulse_block_p)i0=1;
 
   /* too low/high an ATH floater is nonsensical, but doesn't break anything */
