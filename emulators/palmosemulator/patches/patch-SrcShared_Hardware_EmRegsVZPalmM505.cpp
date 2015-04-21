$NetBSD: patch-SrcShared_Hardware_EmRegsVZPalmM505.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsVZPalmM505.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsVZPalmM505.cpp
@@ -52,7 +52,7 @@ void EmRegsVZPalmM505::SetSubBankHandler
 
 	this->SetHandler ((ReadFunction) &EmRegsVZ::StdRead,
 		(WriteFunction) &EmRegsVZPalmM505::portFSelectWrite,
-		addressof (portFSelect), sizeof (f68VZ328Regs.portFSelect));
+		my_addressof (portFSelect), sizeof (f68VZ328Regs.portFSelect));
 }
 
 
