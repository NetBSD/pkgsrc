$NetBSD: patch-support_sdbinutils_bfd_asxxxx.c,v 1.1 2013/10/26 23:24:40 joerg Exp $

--- support/sdbinutils/bfd/asxxxx.c.orig	2013-10-23 20:53:26.000000000 +0000
+++ support/sdbinutils/bfd/asxxxx.c
@@ -166,7 +166,7 @@
 
 /* Macros for converting between hex and binary.  */
 
-static const char digs[] = "0123456789ABCDEF";
+/* static const char digs[] = "0123456789ABCDEF"; */
 
 #define NIBBLE(x)    hex_value(x)
 #define HEX(buffer) ((NIBBLE ((buffer)[0])<<4) + NIBBLE ((buffer)[1]))
