$NetBSD: patch-xmlsecurity_source_gpg_SecurityEnvironment.cxx,v 1.1 2024/08/24 02:57:35 ryoon Exp $

--- xmlsecurity/source/gpg/SecurityEnvironment.cxx.orig	2024-08-22 12:17:22.408529108 +0000
+++ xmlsecurity/source/gpg/SecurityEnvironment.cxx
@@ -24,7 +24,7 @@
 #include <tools/urlobj.hxx>
 #endif
 
-#include <key.h>
+#include <gpgme++/key.h>
 #include <keylistresult.h>
 #include <libxml/xmlstring.h>
 #include <xmlsec/base64.h>
