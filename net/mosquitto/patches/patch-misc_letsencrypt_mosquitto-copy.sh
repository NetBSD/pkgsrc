$NetBSD: patch-misc_letsencrypt_mosquitto-copy.sh,v 1.1 2021/01/28 19:46:24 triaxx Exp $

Fix shell portability problem.

--- misc/letsencrypt/mosquitto-copy.sh.orig	2021-01-11 16:49:40.000000000 +0000
+++ misc/letsencrypt/mosquitto-copy.sh
@@ -12,7 +12,7 @@
 # Place this script in /etc/letsencrypt/renewal-hooks/deploy/ and make it
 # executable after editing it to your needs.
 
-if [ ${RENEWED_DOMAINS} == "my-mosquitto-domain" ]; then
+if [ ${RENEWED_DOMAINS} = "my-mosquitto-domain" ]; then
 	# Copy new certificate to Mosquitto directory
 	cp ${RENEWED_LINEAGE}/fullchain.pem /etc/mosquitto/certs/server.pem
 	cp ${RENEWED_LINEAGE}/privkey.pem /etc/mosquitto/certs/server.key
