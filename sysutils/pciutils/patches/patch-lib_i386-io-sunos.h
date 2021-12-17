$NetBSD: patch-lib_i386-io-sunos.h,v 1.2 2021/12/17 20:07:24 maya Exp $

Fix assembly syntax to work with clang.

--- lib/i386-io-sunos.h.orig	2019-02-13 10:05:03.000000000 +0000
+++ lib/i386-io-sunos.h
@@ -27,7 +27,7 @@ static inline u8
 inb (u16 port)
 {
   u8 v;
-  __asm__ __volatile__ ("inb (%w1)":"=a" (v):"Nd" (port));
+  __asm__ __volatile__ ("inb %w1":"=a" (v):"Nd" (port));
   return v;
 }
 
@@ -35,7 +35,7 @@ static inline u16
 inw (u16 port)
 {
   u16 v;
-  __asm__ __volatile__ ("inw (%w1)":"=a" (v):"Nd" (port));
+  __asm__ __volatile__ ("inw %w1":"=a" (v):"Nd" (port));
   return v;
 }
 
@@ -43,26 +43,26 @@ static inline u32
 inl (u16 port)
 {
   u32 v;
-  __asm__ __volatile__ ("inl (%w1)":"=a" (v):"Nd" (port));
+  __asm__ __volatile__ ("inl %w1":"=a" (v):"Nd" (port));
   return v;
 }
 
 static inline void
 outb (u8 value, u16 port)
 {
-  __asm__ __volatile__ ("outb (%w1)": :"a" (value), "Nd" (port));
+  __asm__ __volatile__ ("outb %w1": :"a" (value), "Nd" (port));
 }
 
 static inline void
 outw (u16 value, u16 port)
 {
-  __asm__ __volatile__ ("outw (%w1)": :"a" (value), "Nd" (port));
+  __asm__ __volatile__ ("outw %w1": :"a" (value), "Nd" (port));
 }
 
 static inline void
 outl (u32 value, u16 port)
 {
-  __asm__ __volatile__ ("outl (%w1)": :"a" (value), "Nd" (port));
+  __asm__ __volatile__ ("outl %w1": :"a" (value), "Nd" (port));
 }
 
 static inline void intel_io_lock(void)
