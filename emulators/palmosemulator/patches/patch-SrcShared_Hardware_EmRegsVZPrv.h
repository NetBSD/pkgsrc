$NetBSD: patch-SrcShared_Hardware_EmRegsVZPrv.h,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsVZPrv.h.orig	2015-04-17 19:10:13.000000000 +0000
+++ SrcShared/Hardware/EmRegsVZPrv.h
@@ -24,7 +24,7 @@ const uint32	kMemorySize		= sizeof (HwrM
 
 // Macro to return the DragonballVZ address of the specified register
 
-#define addressof(x)	(kMemoryStart + offsetof(HwrM68VZ328Type, x))
+#define my_addressof(x)	(kMemoryStart + offsetof(HwrM68VZ328Type, x))
 
 
 // Macros for reading/writing DragonballVZ registers.
@@ -39,7 +39,7 @@ const uint32	kMemorySize		= sizeof (HwrM
 // Macro for installing DragonballVZ register handlers
 
 #define INSTALL_HANDLER(read, write, reg) \
-	this->SetHandler ((ReadFunction) &EmRegsVZ::read, (WriteFunction) &EmRegsVZ::write, addressof (reg), sizeof (f68VZ328Regs.reg))
+	this->SetHandler ((ReadFunction) &EmRegsVZ::read, (WriteFunction) &EmRegsVZ::write, my_addressof (reg), sizeof (f68VZ328Regs.reg))
 
 
 #endif	/* EmRegsVZPrv_h */
