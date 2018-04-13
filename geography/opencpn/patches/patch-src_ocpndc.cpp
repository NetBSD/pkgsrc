$NetBSD: patch-src_ocpndc.cpp,v 1.2 2018/04/13 18:57:29 bouyer Exp $
For some reason ocpnDC::DrawEllipse and ocpnDC::DrawRounderRectangle
and is miscompiled on NetBSD 8.0_BETA and gcc 6.4 from HEAD earmv7hf:
for the tail call to dc->DrawEllipse() the compiler emits a bx instruction,
but forgets to load the address of the function in the register.
The memory barrier works around this problem by avoiding the tail-call
optimisation.
Other similar functions in this file are properly compiled ...
I suspect it's related to the vfp register use in these functions.

--- src/ocpndc.cpp.orig	2018-02-07 12:08:26.000000000 +0100
+++ src/ocpndc.cpp	2018-04-13 15:31:34.958778133 +0200
@@ -716,6 +716,9 @@
         }
     }
 #endif    
+#ifdef __arm__
+    asm volatile("" ::: "memory");
+#endif
 }
 
 void ocpnDC::DrawCircle( wxCoord x, wxCoord y, wxCoord radius )
@@ -775,6 +778,9 @@
         glDisable( GL_BLEND );
     }
 #endif    
+#ifdef __arm__
+    asm volatile("" ::: "memory");
+#endif
 }
 
 void ocpnDC::DrawPolygon( int n, wxPoint points[], wxCoord xoffset, wxCoord yoffset, float scale )
