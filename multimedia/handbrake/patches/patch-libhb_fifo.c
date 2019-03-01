$NetBSD: patch-libhb_fifo.c,v 1.1 2019/03/01 23:51:48 ryoon Exp $

* NetBSD has no memalign

--- libhb/fifo.c.orig	2019-02-22 16:23:51.000000000 +0000
+++ libhb/fifo.c
@@ -13,7 +13,7 @@
 #endif
 
 #ifndef SYS_DARWIN
-#if defined( SYS_FREEBSD ) || defined ( __FreeBSD__ )
+#if defined( SYS_FREEBSD ) || defined ( __FreeBSD__ ) || defined(__NetBSD__)
 #include <stdlib.h>
 #else
 #include <malloc.h>
@@ -395,7 +395,7 @@ hb_buffer_t * hb_buffer_init_internal( i
 
     if (size)
     {
-#if defined( SYS_DARWIN ) || defined( SYS_FREEBSD ) || defined ( __FreeBSD__ ) || defined( SYS_MINGW )
+#if defined( SYS_DARWIN ) || defined( SYS_FREEBSD ) || defined ( __FreeBSD__ ) || defined( SYS_MINGW ) || defined(__NetBSD__)
         b->data  = malloc( b->alloc );
 #elif defined( SYS_CYGWIN )
         /* FIXME */
@@ -821,7 +821,7 @@ hb_image_t * hb_image_init(int pix_fmt, 
     {
         return NULL;
     }
-#if defined( SYS_DARWIN ) || defined( SYS_FREEBSD ) || defined ( __FreeBSD__ ) || defined( SYS_MINGW )
+#if defined( SYS_DARWIN ) || defined( SYS_FREEBSD ) || defined ( __FreeBSD__ ) || defined( SYS_MINGW ) || defined(__NetBSD__)
     image->data  = malloc(size);
 #elif defined( SYS_CYGWIN )
     /* FIXME */
@@ -862,7 +862,7 @@ hb_image_t * hb_buffer_to_image(hb_buffe
 {
     hb_image_t *image = calloc(1, sizeof(hb_image_t));
 
-#if defined( SYS_DARWIN ) || defined( SYS_FREEBSD ) || defined ( __FreeBSD__ ) || defined( SYS_MINGW )
+#if defined( SYS_DARWIN ) || defined( SYS_FREEBSD ) || defined ( __FreeBSD__ ) || defined( SYS_MINGW ) || defined(__NetBSD__)
     image->data  = malloc( buf->size );
 #elif defined( SYS_CYGWIN )
     /* FIXME */
