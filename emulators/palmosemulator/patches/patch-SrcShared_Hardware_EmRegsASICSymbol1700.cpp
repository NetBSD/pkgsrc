$NetBSD: patch-SrcShared_Hardware_EmRegsASICSymbol1700.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsASICSymbol1700.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsASICSymbol1700.cpp
@@ -17,7 +17,7 @@
 // Given a register (specified by its field name), return its address
 // in emulated space.
 
-#define addressof(reg)				\
+#define my_addressof(reg)				\
 	(this->GetAddressStart () + fRegs.offsetof_##reg ())
 
 
@@ -26,7 +26,7 @@
 #define INSTALL_HANDLER(read, write, reg)			\
 	this->SetHandler (	(ReadFunction) &EmRegsASICSymbol1700::read,		\
 						(WriteFunction) &EmRegsASICSymbol1700::write,		\
-						addressof (reg),			\
+						my_addressof (reg),			\
 						fRegs.reg.GetSize ())
 
 
@@ -117,15 +117,15 @@ void EmRegsASICSymbol1700::SetSubBankHan
 		// installation of a field that's an array.
 	this->SetHandler (	(ReadFunction) &EmRegsASICSymbol1700::StdReadBE,		\
 						(WriteFunction) &EmRegsASICSymbol1700::StdWriteBE,		\
-						addressof (S24IO),				\
+						my_addressof (S24IO),				\
 						64);
 	this->SetHandler (	(ReadFunction) &EmRegsASICSymbol1700::StdReadBE,		\
 						(WriteFunction) &EmRegsASICSymbol1700::StdWriteBE,		\
-						addressof (S24Attribute),		\
+						my_addressof (S24Attribute),		\
 						32);
 	this->SetHandler (	(ReadFunction) &EmRegsASICSymbol1700::StdReadBE,		\
 						(WriteFunction) &EmRegsASICSymbol1700::StdWriteBE,		\
-						addressof (UART8251MacroSelect),\
+						my_addressof (UART8251MacroSelect),\
 						4);
 
 //	INSTALL_HANDLER (StdReadBE,			StdWriteBE,				S24IO);
