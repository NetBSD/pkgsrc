$NetBSD: patch-src_options_baseoption.cpp,v 1.1 2025/12/21 12:32:37 markd Exp $

Don't have __BYTE_ORDER

--- src/options/baseoption.cpp.orig	2025-10-04 15:51:38.000000000 +0000
+++ src/options/baseoption.cpp
@@ -140,6 +140,11 @@ bool BaseOption::writeData(void *data)
 
 void BaseOption::readValue() {}
 
+#ifndef __BYTE_ORDER
+#define __BYTE_ORDER _BYTE_ORDER
+#define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#endif
+
 SANE_Word BaseOption::toSANE_Word(unsigned char *data)
 {
     SANE_Word tmp;
