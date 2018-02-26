$NetBSD: patch-xmlsecurity_source_gpg_CertificateImpl.hxx,v 1.2 2018/02/26 18:04:31 ryoon Exp $

* Do not confuse with key.h from gpgmepp and nss

--- xmlsecurity/source/gpg/CertificateImpl.hxx.orig	2017-07-25 20:26:39.000000000 +0000
+++ xmlsecurity/source/gpg/CertificateImpl.hxx
@@ -26,7 +26,7 @@
 #include <com/sun/star/security/CertificateKind.hpp>
 #include <com/sun/star/security/XCertificate.hpp>
 
-#include <key.h>
+#include <gpgme++/key.h>
 
 class CertificateImpl : public cppu::WeakImplHelper< css::security::XCertificate,
                                                      css::lang::XUnoTunnel >,
