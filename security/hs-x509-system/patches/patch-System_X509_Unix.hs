$NetBSD: patch-System_X509_Unix.hs,v 1.1 2023/01/27 01:50:35 pho Exp $

NetBSD base still doesn't have a certification
store. security/mozilla-rootcerts-openssl is the best what we can use.

--- System/X509/Unix.hs.orig	2023-01-27 01:35:36.902431346 +0000
+++ System/X509/Unix.hs
@@ -31,6 +31,7 @@ defaultSystemPaths =
     , "/system/etc/security/cacerts/"   -- android
     , "/usr/local/share/certs/"         -- freebsd
     , "/etc/ssl/cert.pem"               -- openbsd
+    , "@SYSCONFDIR@/openssl/certs/"     -- netbsd
     ]
 
 envPathOverride :: String
