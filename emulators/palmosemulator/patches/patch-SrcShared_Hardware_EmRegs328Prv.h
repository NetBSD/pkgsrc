$NetBSD: patch-SrcShared_Hardware_EmRegs328Prv.h,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegs328Prv.h.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegs328Prv.h
@@ -24,7 +24,7 @@ const uint32	kMemorySize		= sizeof (HwrM
 
 // Macro to return the Dragonball address of the specified register
 
-#define addressof(x)	(kMemoryStart + offsetof(HwrM68328Type, x))
+#define my_addressof(x)	(kMemoryStart + offsetof(HwrM68328Type, x))
 
 
 // Macros for reading/writing Dragonball registers.
@@ -39,7 +39,7 @@ const uint32	kMemorySize		= sizeof (HwrM
 // Macro for installing Dragonball register handlers
 
 #define INSTALL_HANDLER(read, write, reg) \
-	this->SetHandler ((ReadFunction) &EmRegs328::read, (WriteFunction) &EmRegs328::write, addressof (reg), sizeof (f68328Regs.reg))
+	this->SetHandler ((ReadFunction) &EmRegs328::read, (WriteFunction) &EmRegs328::write, my_addressof (reg), sizeof (f68328Regs.reg))
 
 
 #endif	/* EmRegs328Prv_h */
