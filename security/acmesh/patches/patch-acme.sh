$NetBSD: patch-acme.sh,v 1.1 2024/10/24 14:00:37 ryoon Exp $

* POSIX shell portability.
  https://github.com/acmesh-official/acme.sh/pull/5374

--- acme.sh.orig	2024-10-19 01:09:48.948775478 +0000
+++ acme.sh
@@ -1437,7 +1437,7 @@ _toPkcs() {
   else
     ${ACME_OPENSSL_BIN:-openssl} pkcs12 -export -out "$_cpfx" -inkey "$_ckey" -in "$_ccert" -certfile "$_cca"
   fi
-  if [ "$?" == "0" ]; then
+  if [ "$?" = "0" ]; then
     _savedomainconf "Le_PFXPassword" "$pfxPassword"
   fi
 
