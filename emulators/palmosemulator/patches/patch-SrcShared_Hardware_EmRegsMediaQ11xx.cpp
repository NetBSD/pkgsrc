$NetBSD: patch-SrcShared_Hardware_EmRegsMediaQ11xx.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsMediaQ11xx.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsMediaQ11xx.cpp
@@ -659,7 +659,7 @@
 // Given a register (specified by its field name), return its address
 // in emulated space.
 
-#define addressof(x)	(											\
+#define my_addressof(x)	(											\
 							((emuptr) fRegs.x.GetPtr ()) -			\
 							((emuptr) fRegs.GetPtr ()) +			\
 							((emuptr) this->GetAddressStart ())		\
@@ -671,7 +671,7 @@
 #define INSTALL_HANDLER(read, write, reg)							\
 	this->SetHandler (	(ReadFunction) &EmRegsMediaQ11xx::read,		\
 						(WriteFunction) &EmRegsMediaQ11xx::write,	\
-						addressof (reg), 4)
+						my_addressof (reg), 4)
 
 // Private inline function for reading a LE register.
 
@@ -1456,11 +1456,11 @@ void EmRegsMediaQ11xx::SetSubBankHandler
 
 	this->SetHandler (	(ReadFunction) &EmRegsMediaQ11xx::MQRead,
 						(WriteFunction) &EmRegsMediaQ11xx::invalidateWrite,
-						addressof (cpREG), 0x0400);
+						my_addressof (cpREG), 0x0400);
 
 	this->SetHandler (	(ReadFunction) &EmRegsMediaQ11xx::MQRead,
 						(WriteFunction) &EmRegsMediaQ11xx::SourceFifoWrite,
-						addressof (sfREG), 0x0400);
+						my_addressof (sfREG), 0x0400);
 
 	INSTALL_HANDLER (MQRead,			MQWrite,				udREG[0x00]);
 	INSTALL_HANDLER (MQRead,			MQWrite,				udREG[0x01]);
