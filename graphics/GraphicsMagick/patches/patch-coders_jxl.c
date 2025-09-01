$NetBSD: patch-coders_jxl.c,v 1.1 2025/09/01 14:55:27 kikadf Exp $

* Fix CVE-2025-32460, https://sourceforge.net/p/graphicsmagick/code/ci/8e56520435df50f618a03f2721a39a70a515f1cb/
  Patch from upstream after 1.3.45, unreleased


--- coders/jxl.c.orig	2023-08-12 17:29:53.000000000 +0200
+++ coders/jxl.c
@@ -596,7 +596,7 @@ static Image *ReadJXLImage(const ImageIn
                       ThrowJXLReaderException(ResourceLimitError,MemoryAllocationFailed,image);
                   }
                 grayscale=MagickTrue;
-                pixel_format.num_channels=1;
+                pixel_format.num_channels=image->matte ? 2 : 1;
                 pixel_format.data_type=(basic_info.bits_per_sample <= 8 ? JXL_TYPE_UINT8 :
                                   (basic_info.bits_per_sample <= 16 ? JXL_TYPE_UINT16 :
                                    JXL_TYPE_FLOAT));
@@ -773,10 +773,32 @@ static Image *ReadJXLImage(const ImageIn
             size_t
               out_len;
 
+            if (image->logging)
+              (void) LogMagickEvent(CoderEvent,GetMagickModule(),
+                                    "JxlPixelFormat:\n"
+                                    "    num_channels: %u\n"
+                                    "    data_type: %s\n"
+                                    "    endianness: %s\n"
+                                    "    align: %" MAGICK_SIZE_T_F "u",
+                                    pixel_format.num_channels,
+                                    pixel_format.data_type == JXL_TYPE_FLOAT ? "float" :
+                                    (pixel_format.data_type == JXL_TYPE_UINT8 ? "uint8" :
+                                     (pixel_format.data_type == JXL_TYPE_UINT16 ? "uint16" :
+                                      (pixel_format.data_type == JXL_TYPE_FLOAT16 ? "float16" :
+                                       "unknown"))) ,
+                                    pixel_format.endianness == JXL_NATIVE_ENDIAN ? "native" :
+                                    (pixel_format.endianness == JXL_LITTLE_ENDIAN ? "little" :
+                                     (pixel_format.endianness == JXL_BIG_ENDIAN ? "big" : "unknown")),
+                                    pixel_format.align);
+
             status=JxlDecoderImageOutBufferSize(jxl_decoder,&pixel_format,&out_len);
             if (status != JXL_DEC_SUCCESS)
               break;
 
+            if (image->logging)
+              (void) LogMagickEvent(CoderEvent,GetMagickModule(),
+                                    "JxlDecoderImageOutBufferSize() returns %" MAGICK_SIZE_T_F "u",
+                                    (MAGICK_SIZE_T) out_len);
             out_buf=MagickAllocateResourceLimitedArray(unsigned char *,out_len,sizeof(*out_buf));
             if (out_buf == (unsigned char *) NULL)
               ThrowJXLReaderException(ResourceLimitError,MemoryAllocationFailed,image);
