$NetBSD: patch-src_crypto_aes__endian.h,v 1.1 2014/01/05 01:01:48 rumko Exp $

Fix build on DragonFly.

--- src/crypto/aes_endian.h.orig	2008-08-01 19:03:05.000000000 +0000
+++ src/crypto/aes_endian.h
@@ -34,7 +34,7 @@
 /* Include files where endian defines and byteswap functions may reside */
 #if defined( __sun )
 #  include <sys/isa_defs.h>
-#elif defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
+#elif defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ ) || defined( __DragonFly__ )
 #  include <sys/endian.h>
 #elif defined( BSD ) && ( BSD >= 199103 ) || defined( __APPLE__ ) || \
       defined( __CYGWIN32__ ) || defined( __DJGPP__ ) || defined( __osf__ )
