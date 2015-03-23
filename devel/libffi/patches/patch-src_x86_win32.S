$NetBSD: patch-src_x86_win32.S,v 1.1 2015/03/23 15:34:18 jperkin Exp $

Disable incompatible assembly sections on 32-bit OSX.  Based on MacPorts fix
in http://trac.macports.org/ticket/44170

--- src/x86/win32.S.orig	2014-11-11 14:41:37.000000000 +0000
+++ src/x86/win32.S
@@ -1182,6 +1182,7 @@ L_ffi_closure_WIN32_inner$stub:
         hlt ; hlt ; hlt ; hlt ; hlt
 #endif
 
+#if !defined(X86_DARWIN)
 #if defined(X86_WIN32) && !defined(__OS2__)
         .section	.eh_frame,"w"
 #endif
@@ -1343,6 +1344,7 @@ L_ffi_closure_WIN32_inner$stub:
         /* End of DW_CFA_xxx CFI instructions.  */
         .align 4
 .LEFDE5:
+#endif /* X86_DARWIN */
 
 #endif /* !_MSC_VER */
 
