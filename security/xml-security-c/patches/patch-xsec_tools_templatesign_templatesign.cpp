$NetBSD: patch-xsec_tools_templatesign_templatesign.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/tools/templatesign/templatesign.cpp.orig	2015-01-30 03:55:09.000000000 +0000
+++ xsec/tools/templatesign/templatesign.cpp
@@ -726,7 +726,7 @@ int main(int argc, char **argv) {
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
@@ -739,7 +739,7 @@ int main(int argc, char **argv) {
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_EC) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_EC) {
 					cerr << "EC Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
@@ -749,7 +749,7 @@ int main(int argc, char **argv) {
 			}
 #   endif
             else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
