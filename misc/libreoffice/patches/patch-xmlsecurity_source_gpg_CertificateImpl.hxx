$NetBSD: patch-xmlsecurity_source_gpg_CertificateImpl.hxx,v 1.4 2020/11/24 14:33:22 ryoon Exp $

* Do not confuse with key.h from security/gpgme and devel/nss

--- xmlsecurity/source/gpg/CertificateImpl.hxx.orig	2018-08-02 19:54:54.000000000 +0000
+++ xmlsecurity/source/gpg/CertificateImpl.hxx
@@ -31,7 +31,7 @@
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Wundef"
 #endif
-#include <key.h>
+#include <gpgme++/key.h>
 #if defined _MSC_VER && defined __clang__
 #pragma clang diagnostic pop
 #endif
