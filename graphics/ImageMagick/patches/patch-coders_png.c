$NetBSD: patch-coders_png.c,v 1.1 2012/07/30 09:20:08 wiz Exp $

Tom Lane (tgl@redhat.com) found an issue in ImageMagick. Basically
CVE-2011-3026 deals with libpng memory allocation, limitations have been
added so that a bad PNG can't cause the system to allocate a lot of
memory causing a denial of service. However on further investigation of
ImageMagick Tom Lane found that PNG malloc function (Magick_png_malloc)
in turn calls AcquireMagickMemory with an improper size argument:

#ifdef PNG_USER_MEM_SUPPORTED
static png_voidp Magick_png_malloc(png_structp png_ptr,png_uint_32 size)
{
  (void) png_ptr;
  return((png_voidp) AcquireMagickMemory((size_t) size));
}

This is incorrect, the size argument should be declared
png_alloc_size_t according to 1.5, or png_size_t according to 1.2.

"As this function stands, it invisibly does the wrong thing for any
request over 4GB.  On big-endian architectures it very possibly will
do the wrong thing even for requests less than that. So the reason why
the hard-wired 4GB limit prevents a core dump is that it masks the ABI
mismatch here."

So basically we have memory allocations problems that can probably
lead to a denial of service.

For more information please see:

https://bugzilla.redhat.com/show_bug.cgi?id=844101
https://bugzilla.redhat.com/show_bug.cgi?id=844105

--- coders/png.c.orig	2012-04-12 01:52:11.000000000 +0000
+++ coders/png.c
@@ -1756,7 +1756,7 @@ static void MagickPNGWarningHandler(png_
 }
 
 #ifdef PNG_USER_MEM_SUPPORTED
-static png_voidp Magick_png_malloc(png_structp png_ptr,png_uint_32 size)
+static png_voidp Magick_png_malloc(png_structp png_ptr,png_alloc_size_t size)
 {
   (void) png_ptr;
   return((png_voidp) AcquireMagickMemory((size_t) size));
