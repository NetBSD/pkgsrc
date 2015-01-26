$NetBSD: patch-src_portable__c.c,v 1.1 2015/01/26 13:35:37 pho Exp $

Remove kludge for MacPorts bug, otherwise linking against pkgsrc
libiconv will fail due to symbol name mismatch.

--- src/portable_c.c.orig	2014-08-19 12:22:20.000000000 +0000
+++ src/portable_c.c
@@ -1,9 +1,3 @@
-#if (defined(__APPLE__) || defined(macintosh)) && !defined(DMG_BUILD)
-// define this before including iconv.h to avoid a mapping of
-// iconv_open and friends to libicon_open (done by mac ports),
-// while the symbols without 'lib' are linked from /usr/lib/libiconv
-#define LIBICONV_PLUG
-#endif
 #include <iconv.h>
 
 // These functions are implemented in a C file, because there are different
