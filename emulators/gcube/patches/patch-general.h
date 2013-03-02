$NetBSD: patch-general.h,v 1.1 2013/03/02 18:13:14 joerg Exp $

--- general.h.orig	2013-03-01 16:14:47.000000000 +0000
+++ general.h
@@ -81,7 +81,7 @@ char *kill_extension (char *filename);
 char *get_home_dir (void);
 
 __u32 round_up (__u32 a, __u32 b);
-inline int is_power_of_two (__u32 a);
+int is_power_of_two (__u32 a);
 
 __u32 crc_setup (unsigned int bits);
 __u32 crc_iterate (__u32 crc, __u8 d);
