$NetBSD: patch-tools_parser_rfcomm.h,v 1.1 2014/12/30 08:39:13 plunky Exp $

not needed

--- tools/parser/rfcomm.h.orig	2012-12-24 17:46:55.000000000 +0000
+++ tools/parser/rfcomm.h
@@ -25,7 +25,9 @@
 #ifndef __RFCOMM_H
 #define __RFCOMM_H
 
+#if 0
 #include <endian.h>
+#endif
 
 #define RFCOMM_PSM 3
 
