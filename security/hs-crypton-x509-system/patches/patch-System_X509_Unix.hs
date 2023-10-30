$NetBSD: patch-System_X509_Unix.hs,v 1.1 2023/10/30 14:46:29 pho Exp $

Add a certificate path for NetBSD.

https://github.com/kazu-yamamoto/crypton-certificate/pull/5

--- System/X509/Unix.hs.orig	2023-10-08 04:56:31.433165312 +0000
+++ System/X509/Unix.hs
@@ -31,6 +31,7 @@ defaultSystemPaths =
     , "/system/etc/security/cacerts/"   -- android
     , "/usr/local/share/certs/"         -- freebsd
+    , "/etc/openssl/certs/"             -- netbsd
     , "/etc/ssl/cert.pem"               -- openbsd
     ]
 
 envPathOverride :: String
