$NetBSD: patch-plug-ins_rawphoto_dcraw.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- plug-ins/rawphoto/dcraw.c.orig	2009-01-13 15:24:44.000000000 +0000
+++ plug-ins/rawphoto/dcraw.c
@@ -39,6 +39,7 @@
 #include <string.h>
 #include <time.h>
 #include <sys/types.h>
+#include <locale.h>
 /*
    NO_JPEG disables decoding of compressed Kodak DC120 files.
    NO_LCMS disables the "-p" option.
