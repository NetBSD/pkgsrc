$NetBSD: patch-src_SelfSignedCertificate.h,v 1.1 2024/03/21 10:34:10 nia Exp $

From f4cea62ed95e4967d8591f25e903f5e8fc2e2a30 Mon Sep 17 00:00:00 2001
From: Terry Geng <terry@terriex.com>
Date: Mon, 6 Dec 2021 10:45:11 -0500
Subject: [PATCH] BUILD(crypto): Migrate to OpenSSL 3.0-compatible API

OpenSSL 3.0 deprecated several low-level APIs and the usage of them
caused errors/warnings that prevent the binary from being built against
OpenSSL 3.0.
Some primitive efforts have been made in #5317 but were incomplete.
This commit follows https://www.openssl.org/docs/man3.0/man7/migration_guide.html,
https://code.woboq.org/qt6/qtopcua/src/opcua/x509/qopcuakeypair_openssl.cpp.html,
and clears all errors/warnings related to the usage of deprecated APIs.

--- src/SelfSignedCertificate.h.orig	2022-09-13 17:24:40.000000000 +0000
+++ src/SelfSignedCertificate.h
@@ -6,6 +6,10 @@
 #ifndef MUMBLE_SELFSIGNEDCERTIFICATE_H_
 #define MUMBLE_SELFSIGNEDCERTIFICATE_H_
 
+#include <openssl/evp.h>
+#include <openssl/rsa.h>
+#include <openssl/x509v3.h>
+
 #include <QtCore/QString>
 #include <QtNetwork/QSslCertificate>
 #include <QtNetwork/QSslKey>
@@ -16,6 +20,7 @@ class SelfSignedCertificate {
 private:
 	static bool generate(CertificateType certificateType, QString clientCertName, QString clientCertEmail,
 						 QSslCertificate &qscCert, QSslKey &qskKey);
+	static EVP_PKEY *generate_rsa_keypair();
 
 public:
 	static bool generateMumbleCertificate(QString name, QString email, QSslCertificate &qscCert, QSslKey &qskKey);
