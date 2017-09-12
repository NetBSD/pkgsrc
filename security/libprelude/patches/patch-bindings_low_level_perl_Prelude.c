$NetBSD: patch-bindings_low_level_perl_Prelude.c,v 1.1 2017/09/12 06:04:47 dholland Exp $

Don't undef bool; it breaks the build.

--- bindings/low-level/perl/Prelude.c~	2009-08-11 15:13:59.000000000 +0000
+++ bindings/low-level/perl/Prelude.c
@@ -1425,7 +1425,7 @@ SWIG_Perl_SetModule(swig_module_info *mo
   #undef eof
 #endif
 #ifdef bool
-  #undef bool
+//  #undef bool
 #endif
 #ifdef close
   #undef close
