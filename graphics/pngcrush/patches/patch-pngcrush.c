$NetBSD: patch-pngcrush.c,v 1.1 2024/02/01 09:14:54 wiz Exp $

PNG_IGNORE_ADLER32 was deprecated in png-1.6.42
https://github.com/pnggroup/libpng/pull/514

--- pngcrush.c.orig	2024-02-01 09:09:19.207140753 +0000
+++ pngcrush.c
@@ -5520,8 +5520,6 @@ int main(int argc, char *argv[])
                      * they were already checked in the pngcrush_measure_idat
                      * function
                      */
-                    png_set_option(read_ptr, PNG_IGNORE_ADLER32,
-                        PNG_OPTION_ON);
                     png_set_crc_action(read_ptr, PNG_CRC_QUIET_USE,
                                        PNG_CRC_QUIET_USE);
                 }
