$NetBSD: patch-SrcShared_Hardware_EmRegsUSBVisor.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsUSBVisor.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsUSBVisor.cpp
@@ -22,7 +22,7 @@
 // Given a register (specified by its field name), return its address
 // in emulated space.
 
-#define addressof(reg)				\
+#define my_addressof(reg)				\
 	(this->GetAddressStart () + fRegs.offsetof_##reg ())
 
 
@@ -31,7 +31,7 @@
 #define INSTALL_HANDLER(read, write, reg)			\
 	this->SetHandler (	(ReadFunction) &EmRegsUSBVisor::read,		\
 						(WriteFunction) &EmRegsUSBVisor::write,		\
-						addressof (reg),			\
+						my_addressof (reg),			\
 						fRegs.reg.GetSize ())
 
 
