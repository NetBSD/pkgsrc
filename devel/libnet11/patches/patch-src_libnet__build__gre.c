$NetBSD: patch-src_libnet__build__gre.c,v 1.1 2012/05/04 16:11:02 joerg Exp $

--- src/libnet_build_gre.c.orig	2012-04-27 15:03:53.000000000 +0000
+++ src/libnet_build_gre.c
@@ -138,7 +138,7 @@ __libnet_print_gre_flags_ver(u_int16_t f
 
 
 /* FIXME: what is the portability of the "((struct libnet_gre_hdr*)0)->" ? */
-inline u_int32_t
+u_int32_t
 libnet_getgre_length(u_int16_t fv)
 {
 
