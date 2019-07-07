$NetBSD: patch-libdiscmage_misc__z.h,v 1.1 2019/07/07 22:47:57 wiz Exp $

Patch from upstream to improve build on NetBSD.

--- libdiscmage/misc_z.h.orig	2017-05-05 10:26:38.000000000 +0000
+++ libdiscmage/misc_z.h
@@ -1,7 +1,7 @@
 /*
 misc_z.h - miscellaneous zlib functions
 
-Copyright (c) 2001 - 2004, 2016 - 2017 dbjh
+Copyright (c) 2001 - 2004, 2016 - 2017, 2019 dbjh
 
 
 This program is free software; you can redistribute it and/or modify
@@ -58,6 +58,7 @@ extern off_t q_fsize2 (const char *filen
 #define fseek(FILE, OFFSET, MODE) fseek2(FILE, OFFSET, MODE)
 #define fread(BUF, SIZE, NUM, FILE) fread2(BUF, SIZE, NUM, FILE)
 #define fgetc(FILE) fgetc2(FILE)
+#undef  fgets                                   // necessary on (at least) NetBSD
 #define fgets(BUF, MAXLEN, FILE) fgets2(BUF, MAXLEN, FILE)
 #undef  feof                                    // necessary on (at least) Cygwin
 #define feof(FILE) feof2(FILE)
