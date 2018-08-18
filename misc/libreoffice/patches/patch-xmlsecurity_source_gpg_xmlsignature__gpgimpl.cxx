$NetBSD: patch-xmlsecurity_source_gpg_xmlsignature__gpgimpl.cxx,v 1.3 2018/08/18 00:11:32 ryoon Exp $

* Do not confuse with key.h from gpgmepp and nss

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
