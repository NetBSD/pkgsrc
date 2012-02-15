$NetBSD: patch-src_p__exe.h,v 1.1 2012/02/15 19:27:10 hans Exp $

--- src/p_exe.h.orig	2002-06-01 13:20:17.000000000 +0200
+++ src/p_exe.h	2012-01-11 15:33:21.472848400 +0100
@@ -96,7 +96,7 @@ protected:
     enum {
         NORELOC = 1,
         USEJUMP = 2,
-        SS = 4,
+        upx_SS = 4,
         SP = 8,
         MINMEM = 16,
         MAXMEM = 32
