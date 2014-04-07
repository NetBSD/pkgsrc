$NetBSD: patch-src_psd.imageio_psdinput.cpp,v 1.1 2014/04/07 12:15:55 ryoon Exp $

--- src/psd.imageio/psdinput.cpp.orig	2014-04-03 06:08:57.000000000 +0000
+++ src/psd.imageio/psdinput.cpp
@@ -389,7 +389,7 @@ private:
         // For debugging, numeric_cast will throw if precision is lost:
         // value = boost::numeric_cast<TVariable>(buffer);
         value = buffer;
-        return m_file;
+        return !m_file.bad();
     }
 
     int read_pascal_string (std::string &s, uint16_t mod_padding);
