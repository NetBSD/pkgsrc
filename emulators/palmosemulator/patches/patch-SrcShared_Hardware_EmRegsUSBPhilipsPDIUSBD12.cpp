$NetBSD: patch-SrcShared_Hardware_EmRegsUSBPhilipsPDIUSBD12.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsUSBPhilipsPDIUSBD12.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsUSBPhilipsPDIUSBD12.cpp
@@ -18,8 +18,8 @@
 // Given a register (specified by its field name), return its address
 // in emulated space.
 
-#undef addressof
-#define addressof(reg)				\
+#undef my_addressof
+#define my_addressof(reg)				\
 	(this->GetAddressStart () + fRegs.offsetof_##reg ())
 
 
@@ -29,7 +29,7 @@
 #define INSTALL_HANDLER(read, write, reg)			\
 	this->SetHandler (	(ReadFunction) &EmRegsUSBPhilipsPDIUSBD12::read,		\
 						(WriteFunction) &EmRegsUSBPhilipsPDIUSBD12::write,		\
-						addressof (reg),			\
+						my_addressof (reg),			\
 						fRegs.reg.GetSize ())
 
 
