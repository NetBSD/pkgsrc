$NetBSD: patch-lib-src_enigma-core_ecl_dict.hh,v 1.1 2011/02/23 10:20:26 adam Exp $

Fix C++ error.

--- lib-src/enigma-core/ecl_dict.hh.orig	2011-02-22 13:20:39.000000000 +0000
+++ lib-src/enigma-core/ecl_dict.hh
@@ -27,6 +27,7 @@ namespace ecl
     extern unsigned hash(const std::string &key);
 
     class XInvalidKey : XGeneric {
+    public:
 	XInvalidKey () : XGeneric("invalid dictionary key")
         {}
     };
