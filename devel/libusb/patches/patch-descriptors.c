$NetBSD: patch-descriptors.c,v 1.1 2019/08/06 09:12:10 maya Exp $

Avoid unaligned access. This breaks clang.
Improve consistency.

--- descriptors.c.orig	2006-03-04 02:52:46.000000000 +0000
+++ descriptors.c
@@ -39,17 +39,17 @@ int usb_parse_descriptor(unsigned char *
   for (cp = description; *cp; cp++) {
     switch (*cp) {
     case 'b':	/* 8-bit byte */
-      *dp++ = *sp++;
+      memcpy(dp, sp, 1); sp += 1; dp += 1;
       break;
     case 'w':	/* 16-bit word, convert from little endian to CPU */
-      w = (sp[1] << 8) | sp[0]; sp += 2;
+      w = (sp[1] << 8) | sp[0];
       dp += ((unsigned long)dp & 1);	/* Align to word boundary */
-      *((uint16_t *)dp) = w; dp += 2;
+      memcpy(dp, &w, 2); sp += 2; dp += 2;
       break;
     case 'd':	/* 32-bit dword, convert from little endian to CPU */
-      d = (sp[3] << 24) | (sp[2] << 16) | (sp[1] << 8) | sp[0]; sp += 4;
+      d = (sp[3] << 24) | (sp[2] << 16) | (sp[1] << 8) | sp[0];
       dp += ((unsigned long)dp & 2);	/* Align to dword boundary */
-      *((uint32_t *)dp) = d; dp += 4;
+      memcpy(dp, &d, 4); sp += 4; dp += 4;
       break;
     /* These two characters are undocumented and just a hack for Linux */
     case 'W':	/* 16-bit word, keep CPU endianess */
