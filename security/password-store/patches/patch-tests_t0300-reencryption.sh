$NetBSD: patch-tests_t0300-reencryption.sh,v 1.1 2018/05/06 11:56:58 leot Exp $

Adjust output for gnupg2>=2.2.5.

--- tests/t0300-reencryption.sh.orig	2017-04-13 10:11:14.000000000 +0000
+++ tests/t0300-reencryption.sh
@@ -10,7 +10,7 @@ canonicalize_gpg_keys() {
 	$GPG --list-keys --with-colons "$@" | sed -n 's/sub:[^:]*:[^:]*:[^:]*:\([^:]*\):[^:]*:[^:]*:[^:]*:[^:]*:[^:]*:[^:]*:[a-zA-Z]*e[a-zA-Z]*:.*/\1/p' | LC_ALL=C sort -u
 }
 gpg_keys_from_encrypted_file() {
-	$GPG -v --no-secmem-warning --no-permission-warning --decrypt --list-only --keyid-format long "$1" 2>&1 | cut -d ' ' -f 5 | LC_ALL=C sort -u
+	$GPG -v --no-secmem-warning --no-permission-warning --decrypt --list-only --keyid-format long "$1" 2>&1 | sed -n '/public key/p' | cut -d ' ' -f 5 | LC_ALL=C sort -u
 }
 gpg_keys_from_group() {
 	local output="$($GPG --list-config --with-colons | sed -n "s/^cfg:group:$1:\\(.*\\)/\\1/p" | head -n 1)"
