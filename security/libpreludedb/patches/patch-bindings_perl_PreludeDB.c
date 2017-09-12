$NetBSD: patch-bindings_perl_PreludeDB.c,v 1.1 2017/09/12 06:04:59 dholland Exp $

Don't undef bool; it breaks the build.

--- bindings/perl/PreludeDB.c~	2009-07-15 07:38:21.000000000 +0000
+++ bindings/perl/PreludeDB.c
@@ -1425,7 +1425,7 @@ SWIG_Perl_SetModule(swig_module_info *mo
   #undef eof
 #endif
 #ifdef bool
-  #undef bool
+//  #undef bool
 #endif
 #ifdef close
   #undef close
