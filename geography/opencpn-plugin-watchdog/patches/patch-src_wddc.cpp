$NetBSD: patch-src_wddc.cpp,v 1.1 2018/04/19 09:59:28 bouyer Exp $

Same problem as opencpn/patches/patch-src_ocpndc.cpp:

For some reason wdDC::DrawEllipse is miscompiled on NetBSD 8.0_BETA and
gcc 6.4 from HEAD earmv7hf:
for the tail call to dc->DrawEllipse() the compiler emits a bx instruction,
but forgets to load the address of the function in the register.
The memory barrier works around this problem by avoiding the tail-call
optimisation.
Other similar functions in this file are properly compiled ...
I suspect it's related to the vfp register use in these functions.

wdDC::DrawRoundedRectangle appears to be compiled OK, but it's similar
to ocpnDC::DrawRounderRectangle so to be safe I apply the hack here as well.

--- src/wddc.cpp.orig	2018-04-19 11:16:39.711460532 +0200
+++ src/wddc.cpp	2018-04-19 11:21:45.535313650 +0200
@@ -712,6 +712,9 @@
         
     }
 #endif    
+#ifdef __arm__
+    asm volatile("" ::: "memory");
+#endif
 }
 
 void wdDC::DrawCircle( wxCoord x, wxCoord y, wxCoord radius )
@@ -771,6 +774,9 @@
         glDisable( GL_BLEND );
     }
 #endif    
+#ifdef __arm__
+    asm volatile("" ::: "memory");
+#endif
 }
 
 void wdDC::DrawPolygon( int n, wxPoint points[], wxCoord xoffset, wxCoord yoffset )
