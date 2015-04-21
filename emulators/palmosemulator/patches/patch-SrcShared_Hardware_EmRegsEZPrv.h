$NetBSD: patch-SrcShared_Hardware_EmRegsEZPrv.h,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsEZPrv.h.orig	2015-04-17 19:10:13.000000000 +0000
+++ SrcShared/Hardware/EmRegsEZPrv.h
@@ -24,7 +24,7 @@ const uint32	kMemorySize		= sizeof (HwrM
 
 // Macro to return the DragonballEZ address of the specified register
 
-#define addressof(x)	(kMemoryStart + offsetof(HwrM68EZ328Type, x))
+#define my_addressof(x)	(kMemoryStart + offsetof(HwrM68EZ328Type, x))
 
 
 // Macros for reading/writing DragonballEZ registers.
@@ -39,7 +39,7 @@ const uint32	kMemorySize		= sizeof (HwrM
 // Macro for installing DragonballEZ register handlers
 
 #define INSTALL_HANDLER(read, write, reg) \
-	this->SetHandler ((ReadFunction) &EmRegsEZ::read, (WriteFunction) &EmRegsEZ::write, addressof (reg), sizeof (f68EZ328Regs.reg))
+	this->SetHandler ((ReadFunction) &EmRegsEZ::read, (WriteFunction) &EmRegsEZ::write, my_addressof (reg), sizeof (f68EZ328Regs.reg))
 
 
 #endif	/* EmRegsEZPrv_h */
