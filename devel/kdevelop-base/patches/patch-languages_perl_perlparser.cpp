$NetBSD: patch-languages_perl_perlparser.cpp,v 1.1 2011/11/25 21:45:02 joerg Exp $

--- languages/perl/perlparser.cpp.orig	2011-11-25 19:31:55.000000000 +0000
+++ languages/perl/perlparser.cpp
@@ -464,7 +464,7 @@ void perlparser::getPerlINC() {
             return;
         }
         array.setRawData(buffer, n);
-        result=QString::QString(array);
+        result=QString(array);
         array.resetRawData(buffer, n);
  }
  pclose(fd);
