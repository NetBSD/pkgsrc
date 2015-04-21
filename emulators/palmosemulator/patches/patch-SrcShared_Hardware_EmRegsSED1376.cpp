$NetBSD: patch-SrcShared_Hardware_EmRegsSED1376.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsSED1376.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsSED1376.cpp
@@ -23,7 +23,7 @@
 // Given a register (specified by its field name), return its address
 // in emulated space.
 
-#define addressof(reg)				\
+#define my_addressof(reg)				\
 	(this->GetAddressStart () + fRegs.offsetof_##reg ())
 
 
@@ -32,7 +32,7 @@
 #define INSTALL_HANDLER(read, write, reg)			\
 	this->SetHandler (	(ReadFunction) &EmRegsSED1376::read,		\
 						(WriteFunction) &EmRegsSED1376::write,		\
-						addressof (reg),			\
+						my_addressof (reg),			\
 						fRegs.reg.GetSize ())
 
 // Panel type register [10h]
@@ -457,7 +457,7 @@ void EmRegsSED1376VisorPrism::SetSubBank
 #define INSTALL_HANDLER(read, write, reg)			\
 	this->SetHandler (	(ReadFunction) &EmRegsSED1376VisorPrism::read,		\
 						(WriteFunction) &EmRegsSED1376VisorPrism::write,		\
-						addressof (reg),			\
+						my_addressof (reg),			\
 						fRegs.reg.GetSize ())
 
 	INSTALL_HANDLER (StdReadBE,			reservedWrite,			reserved);
