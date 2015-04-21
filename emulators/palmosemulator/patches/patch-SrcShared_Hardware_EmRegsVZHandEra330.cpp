$NetBSD: patch-SrcShared_Hardware_EmRegsVZHandEra330.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsVZHandEra330.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsVZHandEra330.cpp
@@ -589,20 +589,20 @@ void EmRegsVZHandEra330::SetSubBankHandl
     // SD support
 	this->SetHandler((ReadFunction)&EmRegsVZHandEra330::spiRxDRead,
                          (WriteFunction)&EmRegsVZ::StdWrite,
-	                 addressof(spiRxD),
+	                 my_addressof(spiRxD),
 	                 sizeof(UInt16));
 	this->SetHandler((ReadFunction)&EmRegsVZ::StdRead,
                          (WriteFunction)&EmRegsVZHandEra330::spiTxDWrite,
-	                 addressof(spiTxD),
+	                 my_addressof(spiTxD),
 	                 sizeof(UInt16));
 	this->SetHandler((ReadFunction)&EmRegsVZ::StdRead,
                          (WriteFunction)&EmRegsVZHandEra330::spiCont1Write,
-	                 addressof(spiCont1),
+	                 my_addressof(spiCont1),
 	                 sizeof(UInt16));
 /*
 	this->SetHandler((ReadFunction)&EmRegsVZHandEra330::spiIntCSRead,
                      (WriteFunction)&EmRegsVZHandEra330::spiIntCSWrite,
-	                 addressof(spiIntCS),
+	                 my_addressof(spiIntCS),
 	                 sizeof(regs.spiIntCS));
 */
 }
