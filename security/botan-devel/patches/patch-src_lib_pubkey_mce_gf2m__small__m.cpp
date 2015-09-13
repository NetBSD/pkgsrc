$NetBSD: patch-src_lib_pubkey_mce_gf2m__small__m.cpp,v 1.1 2015/09/13 02:31:22 joerg Exp $

--- src/lib/pubkey/mce/gf2m_small_m.cpp.orig	2015-08-23 21:58:46.266355850 +0000
+++ src/lib/pubkey/mce/gf2m_small_m.cpp
@@ -11,6 +11,7 @@
 #include <botan/gf2m_small_m.h>
 #include <botan/code_based_util.h>
 #include <string>
+#include <stdexcept>
 
 namespace Botan {
 
