$NetBSD: patch-SrcShared_Hardware_EmRegsEZTRGpro.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsEZTRGpro.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsEZTRGpro.cpp
@@ -231,7 +231,7 @@ void EmRegsEZTRGpro::SetSubBankHandlers(
 	EmRegsEZ::SetSubBankHandlers();
 	this->SetHandler((ReadFunction)&EmRegs::StdRead,
                          (WriteFunction)&EmRegsEZTRGpro::spiWrite,
-	                 addressof(spiMasterData),
+	                 my_addressof(spiMasterData),
 	                 sizeof(f68EZ328Regs.spiMasterData));
 }
 
