$NetBSD: patch-output.h,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- output.h.orig	2015-03-17 21:47:35.000000000 +0000
+++ output.h
@@ -80,7 +80,7 @@ void set_color(rgb_color_t c, rgb_color_
  */
 #define writembs( mbs )                         \
         {                                       \
-                char *tmp = mbs;                \
+                const char *tmp = mbs;                \
                 if( tmp )        \
                 {          \
                         writembs_internal( tmp );      \
@@ -104,7 +104,7 @@ void set_color(rgb_color_t c, rgb_color_
    as the sending function. But a weird bug on PPC Linux means that on
    this platform, write is instead used directly.
 */
-int writembs_internal(char *str);
+int writembs_internal(const char *str);
 
 /**
    Write a wide character using the output method specified using output_set_writer().
