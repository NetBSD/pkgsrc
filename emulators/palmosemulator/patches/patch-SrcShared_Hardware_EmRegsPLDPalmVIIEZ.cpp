$NetBSD: patch-SrcShared_Hardware_EmRegsPLDPalmVIIEZ.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsPLDPalmVIIEZ.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsPLDPalmVIIEZ.cpp
@@ -23,7 +23,7 @@
 // Given a register (specified by its field name), return its address
 // in emulated space.
 
-#define addressof(reg)				\
+#define my_addressof(reg)				\
 	(this->GetAddressStart () + fRegs.offsetof_##reg ())
 
 
@@ -32,7 +32,7 @@
 #define INSTALL_HANDLER(read, write, reg)		\
 	this->SetHandler (	(ReadFunction) &EmRegsPLDPalmVIIEZ::read,	\
 						(WriteFunction) &EmRegsPLDPalmVIIEZ::write,	\
-						addressof (reg),		\
+						my_addressof (reg),		\
 						fRegs.reg.GetSize ())
 
 
