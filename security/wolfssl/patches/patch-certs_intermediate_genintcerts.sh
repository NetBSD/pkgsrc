$NetBSD: patch-certs_intermediate_genintcerts.sh,v 1.1 2020/02/03 23:04:09 fox Exp $

Make the script portable.

--- certs/intermediate/genintcerts.sh.orig	2020-01-27 21:06:17.351863728 +0000
+++ certs/intermediate/genintcerts.sh
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
