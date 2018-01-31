$NetBSD: patch-lib_i386-io-sunos.h,v 1.1 2018/01/31 13:21:55 jperkin Exp $

Fix assembly syntax to work with clang.

--- lib/i386-io-sunos.h.orig	2011-01-07 21:04:28.000000000 +0000
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
 
@@ -43,24 +43,24 @@ static inline u32
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
