$NetBSD: patch-extra_wolfssl_wolfssl_certs_intermediate_genintcerts.sh,v 1.1 2021/05/23 15:32:47 nia Exp $

Shell portability.

--- extra/wolfssl/wolfssl/certs/intermediate/genintcerts.sh.orig	2020-01-26 20:43:50.000000000 +0000
+++ extra/wolfssl/wolfssl/certs/intermediate/genintcerts.sh
@@ -175,11 +175,11 @@ create_cert() {
     mv ./certs/intermediate/tmp.pem ./certs/intermediate/$4.pem
 }
 
-if [ "$1" == "clean" ]; then
+if [ "$1" = "clean" ]; then
     echo "Cleaning temp files"
     cleanup_files
 fi
-if [ "$1" == "cleanall" ]; then
+if [ "$1" = "cleanall" ]; then
     echo "Cleaning all files"
     rm -f ./certs/intermediate/*.pem
     rm -f ./certs/intermediate/*.der
