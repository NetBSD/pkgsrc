$NetBSD: patch-coders_jpeg.c,v 1.1 2012/03/30 03:50:47 taca Exp $

* Fix for CVE-2012-0260.

--- coders/jpeg.c.orig	2012-03-02 17:37:45.000000000 +0000
+++ coders/jpeg.c
@@ -319,6 +319,8 @@ static void JPEGErrorHandler(j_common_pt
 
 static MagickBooleanType JPEGWarningHandler(j_common_ptr jpeg_info,int level)
 {
+#define JPEGExcessiveWarnings	1000
+
   char
     message[JMSG_LENGTH_MAX];
 
@@ -337,11 +339,12 @@ static MagickBooleanType JPEGWarningHand
         Process warning message.
       */
       (jpeg_info->err->format_message)(jpeg_info,message);
+      if (jpeg_info->err->num_warnings++ > JPEGExcessiveWarnings)
+	JPEGErrorHandler(jpeg_info);
       if ((jpeg_info->err->num_warnings == 0) ||
           (jpeg_info->err->trace_level >= 3))
         ThrowBinaryException(CorruptImageWarning,(char *) message,
           image->filename);
-      jpeg_info->err->num_warnings++;
     }
   else
     if ((image->debug != MagickFalse) &&
