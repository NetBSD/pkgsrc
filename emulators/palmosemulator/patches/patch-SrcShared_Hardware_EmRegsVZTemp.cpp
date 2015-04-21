$NetBSD: patch-SrcShared_Hardware_EmRegsVZTemp.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsVZTemp.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsVZTemp.cpp
@@ -626,8 +626,8 @@ EmSPISlave* EmRegsVZPalmM130::GetSPISlav
 // Given a register (specified by its field name), return its address
 // in emulated space.
 
-#undef addressof
-#define addressof(reg)				\
+#undef my_addressof
+#define my_addressof(reg)				\
 	(this->GetAddressStart () + fRegs.offsetof_##reg ())
 
 
@@ -637,7 +637,7 @@ EmSPISlave* EmRegsVZPalmM130::GetSPISlav
 #define INSTALL_HANDLER(read, write, reg)		\
 	this->SetHandler (	(ReadFunction) &EmRegsPLDPalmI705::read,	\
 						(WriteFunction) &EmRegsPLDPalmI705::write,	\
-						addressof (reg),		\
+						my_addressof (reg),		\
 						fRegs.reg.GetSize ())
 
 
