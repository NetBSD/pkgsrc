$NetBSD: patch-CryptoPkg_Library_OpensslLib_openssl_.travis-create-release.sh,v 1.1 2019/02/19 16:45:45 ryoon Exp $

* POSIX shell portability

--- CryptoPkg/Library/OpensslLib/openssl/.travis-create-release.sh.orig	2019-01-10 14:13:56.000000000 +0000
+++ CryptoPkg/Library/OpensslLib/openssl/.travis-create-release.sh
@@ -3,7 +3,7 @@
 # $1 is expected to be $TRAVIS_OS_NAME
 
 ./Configure dist
-if [ "$1" == osx ]; then
+if [ "$1" = osx ]; then
     make NAME='_srcdist' TARFILE='_srcdist.tar' \
          TAR_COMMAND='$(TAR) $(TARFLAGS) -cvf -' tar
 else
