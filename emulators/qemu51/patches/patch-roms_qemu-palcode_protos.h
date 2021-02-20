$NetBSD: patch-roms_qemu-palcode_protos.h,v 1.1 2021/02/20 22:55:19 ryoon Exp $

- Don't include system headers.  Instead, provide standalone definitions
  and declarations of types needed and functions used by the PALcode that
  are compatible with the standard Alpha / GCC ABI.
- Add pci_vga_bus and pci_vga_dev globals so that the HWRPB CTB can
  correctly reflect the location of the a graphics console.

--- roms/qemu-palcode/protos.h.orig	2020-10-04 17:05:39.239008051 +0000
+++ roms/qemu-palcode/protos.h	2020-10-04 17:06:01.772319919 +0000
@@ -21,11 +21,33 @@
 #ifndef PROTOS_H
 #define PROTOS_H 1
 
-#include <stdint.h>
-#include <stdbool.h>
-#include <stddef.h>
-#include <string.h>
-
+/*
+ * Stand-alone definitions for various types, compatible with
+ * the Alpha Linux ABI and GCC.  This eliminates dependencies
+ * on external headers.
+ */
+typedef unsigned char  uint8_t;
+typedef unsigned short uint16_t;
+typedef unsigned int   uint32_t;
+typedef unsigned long  uint64_t;
+typedef unsigned long  size_t;
+
+#define	bool	_Bool
+#define	true	1
+#define	false	0
+
+#define	offsetof(type, member) __builtin_offsetof(type, member)
+
+typedef __builtin_va_list va_list;
+#define	va_start(ap, last)	__builtin_va_start((ap), (last))
+#define	va_arg			__builtin_va_arg
+#define	va_end(ap)		__builtin_va_end(ap)
+
+#define	NULL	((void *)0)
+
+extern void *memset(void *, int, size_t);
+extern void *memcpy(void *, const void *, size_t);
+extern size_t strlen(const char *);
 
 /*
  * Call_Pal functions.
@@ -202,6 +224,8 @@ extern unsigned long crb_fixup(unsigned 
  */
 
 extern bool have_vga;
+extern unsigned int pci_vga_bus;
+extern unsigned int pci_vga_dev;
 
 extern void do_console(void);
 extern void entInt(void);
@@ -211,6 +235,7 @@ extern void entInt(void);
  */
 
 extern int printf(const char *, ...);
+extern int puts(const char *);
 extern void ndelay(unsigned long nsec);
 
 static inline void udelay(unsigned long msec)
