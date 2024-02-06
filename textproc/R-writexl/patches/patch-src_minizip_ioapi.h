$NetBSD: patch-src_minizip_ioapi.h,v 1.1 2024/02/06 12:24:08 mef Exp $

** testing if installed package can be loaded from temporary location
Error: package or namespace load failed for 'writexl' in dyn.load(file, DLLpath = DLLpath, ...):
 unable to load shared object '/tmp/W/textproc/R-writexl/work/.destdir/usr/pkg/lib/R/library/00LOCK-writexl/00new/writexl/libs/writexl.so':
  /tmp/W/textproc/R-writexl/work/.destdir/usr/pkg/lib/R/library/00LOCK-writexl/00new/writexl/libs/writexl.so: Undefined PLT symbol "fseeko64" (symnum = 25)
Error: loading failed
Execution halted
ERROR: loading failed
* removing '/tmp/W/textproc/R-writexl/work/.destdir/usr/pkg/lib/R/library/writexl'

--- src/minizip/ioapi.h.orig	2023-01-07 02:19:12.000000000 +0900
+++ src/minizip/ioapi.h	2024-02-06 21:15:18.108719602 +0900
@@ -56,7 +56,7 @@
 #define ftello64 ftell
 #define fseeko64 fseek
 #else
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #define fopen64 fopen
 #define ftello64 ftello
 #define fseeko64 fseeko
