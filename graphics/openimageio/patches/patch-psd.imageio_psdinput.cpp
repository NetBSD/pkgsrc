$NetBSD: patch-psd.imageio_psdinput.cpp,v 1.2 2013/07/05 21:34:12 joerg Exp $

--- psd.imageio/psdinput.cpp.orig	2013-02-21 17:10:46.000000000 +0000
+++ psd.imageio/psdinput.cpp
@@ -328,7 +328,7 @@ private:
         // For debugging, numeric_cast will throw if precision is lost:
         // value = boost::numeric_cast<TVariable>(buffer);
         value = buffer;
-        return m_file;
+        return !m_file.bad();
     }
 
     int read_pascal_string (std::string &s, uint16_t mod_padding);
