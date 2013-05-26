$NetBSD: patch-.._.._ipxe_src_arch_i386_scripts_i386.lds,v 1.1 2013/05/26 20:27:43 bouyer Exp $

--- ../../ipxe/src/arch/i386/scripts/i386.lds.orig	2013-05-26 18:59:26.000000000 +0200
+++ ../../ipxe/src/arch/i386/scripts/i386.lds	2013-05-26 18:59:31.000000000 +0200
@@ -161,7 +161,7 @@
      *
      */
 
-    PROVIDE ( _max_align = 16 );
+    _max_align		    = DEFINED ( _max_align ) ? _max_align : 16;
     .			= 0;
 
     .			= ALIGN ( _max_align );
