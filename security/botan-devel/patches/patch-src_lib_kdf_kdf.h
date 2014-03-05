$NetBSD: patch-src_lib_kdf_kdf.h,v 1.1 2014/03/05 21:22:38 joerg Exp $

--- src/lib/kdf/kdf.h.orig	2014-03-01 16:36:51.000000000 +0000
+++ src/lib/kdf/kdf.h
@@ -10,6 +10,7 @@
 
 #include <botan/secmem.h>
 #include <botan/types.h>
+#include <string>
 
 namespace Botan {
 
