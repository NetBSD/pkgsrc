$NetBSD: patch-src_xmlserializer.hpp,v 1.1 2013/03/28 21:43:11 joerg Exp $

--- src/xmlserializer.hpp.orig	2013-03-27 10:08:42.000000000 +0000
+++ src/xmlserializer.hpp
@@ -22,7 +22,6 @@
 #include "safeserializer.hpp"
 
 class Safe;
-enum Safe::Error;
 class EncryptedString;
 class SecuredString;
 
