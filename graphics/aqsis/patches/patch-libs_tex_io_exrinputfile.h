$NetBSD: patch-libs_tex_io_exrinputfile.h,v 1.1 2013/08/27 15:52:06 joerg Exp $

--- libs/tex/io/exrinputfile.h.orig	2013-08-27 12:56:02.000000000 +0000
+++ libs/tex/io/exrinputfile.h
@@ -48,10 +48,9 @@
 
 #include <aqsis/tex/io/itexinputfile.h>
 
+#include <ImfInputFile.h>
+
 //------------------------------------------------------------------------------
-namespace Imf {
-	class InputFile;
-}
 
 namespace Aqsis {
 
