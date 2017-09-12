$NetBSD: patch-src_ocpndc.cpp,v 1.1 2017/09/12 17:31:20 bouyer Exp $
For some reason ocpnDC::DrawEllipse is miscompiled on NetBSD 8.0_BETA earmv7hf:
for the tail call to dc->DrawEllipse() the compiler emits a bx instruction,
but forgets to load the address of the function in the register.
The memory barrier works around this problem by avoiding the tail-call
optimisation.
Other similar functions in this file are properly compiled ...

--- src/ocpndc.cpp.orig	2017-09-12 15:29:07.101981729 +0200
+++ src/ocpndc.cpp	2017-09-12 17:00:40.945848063 +0200
@@ -769,6 +769,9 @@
         glDisable( GL_BLEND );
     }
 #endif    
+#ifdef __arm__
+	asm volatile("" ::: "memory");
+#endif
 }
 
 void ocpnDC::DrawPolygon( int n, wxPoint points[], wxCoord xoffset, wxCoord yoffset, float scale )
