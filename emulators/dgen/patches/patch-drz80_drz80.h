$NetBSD: patch-drz80_drz80.h,v 1.1 2015/03/31 15:20:53 joerg Exp $

--- drz80/drz80.h.orig	2013-02-09 20:26:18.000000000 +0000
+++ drz80/drz80.h
@@ -63,8 +63,8 @@ struct DrZ80
   void (*z80_out )(unsigned short p,unsigned char d);
   unsigned char (*z80_read8)(unsigned short a);
   unsigned short (*z80_read16)(unsigned short a);
-  unsigned int (*z80_rebaseSP)(unsigned short new_sp);
-  unsigned int (*z80_rebasePC)(unsigned short new_pc);
+  uintptr_t (*z80_rebaseSP)(unsigned short new_sp);
+  uintptr_t (*z80_rebasePC)(unsigned short new_pc);
   unsigned int bla;
 };
 
