$NetBSD: patch-SrcShared_Hardware_EmRegsSED1375.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/Hardware/EmRegsSED1375.cpp.orig	2015-04-17 19:10:12.000000000 +0000
+++ SrcShared/Hardware/EmRegsSED1375.cpp
@@ -25,7 +25,7 @@
 // Given a register (specified by its field name), return its address
 // in emulated space.
 
-#define addressof(reg)				\
+#define my_addressof(reg)				\
 	(this->GetAddressStart () + fRegs.offsetof_##reg ())
 
 
@@ -34,7 +34,7 @@
 #define INSTALL_HANDLER(read, write, reg)			\
 	this->SetHandler (	(ReadFunction) &EmRegsSED1375::read,		\
 						(WriteFunction) &EmRegsSED1375::write,		\
-						addressof (reg),			\
+						my_addressof (reg),			\
 						fRegs.reg.GetSize ())
 
 
@@ -425,7 +425,7 @@ uint32 EmRegsSED1375::lookUpTableDataRea
 	{
 		colorData = (uint8) ((clutEntry & kCLUTBlueMask) << 4);	// Get the 4 bits of blue.
 
-		address = (emuptr) (addressof (lookUpTableAddress));
+		address = (emuptr) (my_addressof (lookUpTableAddress));
 		EmRegsSED1375::lookUpTableAddressWrite (address, 1, (clutIndex + 1) & 0xFF);
 	}
 
@@ -470,7 +470,7 @@ void EmRegsSED1375::lookUpTableDataWrite
 		fClutData[clutIndex] &= ~kCLUTBlueMask; 		// Clear out old red bits.
 		fClutData[clutIndex] |= newColor >> 4;			// Save in new blue bits.
 
-		address = (emuptr) (addressof (lookUpTableAddress));
+		address = (emuptr) (my_addressof (lookUpTableAddress));
 		EmRegsSED1375::lookUpTableAddressWrite (address, 1, (clutIndex + 1) & 0xFF);
 	}
 
