$NetBSD: patch-xmlsecurity_source_gpg_xmlsignature__gpgimpl.cxx,v 1.4 2020/11/24 14:33:22 ryoon Exp $

* Do not confuse with key.h from security/gpgme and devel/nss

--- xmlsecurity/source/gpg/xmlsignature_gpgimpl.cxx.orig	2018-08-02 19:54:54.000000000 +0000
+++ xmlsecurity/source/gpg/xmlsignature_gpgimpl.cxx
@@ -33,7 +33,7 @@
 #pragma clang diagnostic pop
 #endif
 #include <context.h>
-#include <key.h>
+#include <gpgme++/key.h>
 #include <data.h>
 #include <signingresult.h>
 #include <importresult.h>
