$NetBSD: patch-ext_exif_exif.c,v 1.3.2.2 2014/10/25 15:55:51 tron Exp $

* Fix for CVE-2014-3670.

--- ext/exif/exif.c.orig	2014-08-13 19:22:50.000000000 +0000
+++ ext/exif/exif.c
@@ -2446,11 +2446,11 @@ static void* exif_ifd_make_value(image_i
 					data_ptr += 8;
 					break;
 				case TAG_FMT_SINGLE:
-					memmove(data_ptr, &info_data->value.f, byte_count);
+					memmove(data_ptr, &info_value->f, 4);
 					data_ptr += 4;
 					break;
 				case TAG_FMT_DOUBLE:
-					memmove(data_ptr, &info_data->value.d, byte_count);
+					memmove(data_ptr, &info_value->d, 8);
 					data_ptr += 8;
 					break;
 			}
