$NetBSD: patch-packages_clib_sha1_brg_endian.h,v 1.2 2014/05/28 10:29:12 markd Exp $

--- packages/clib/sha1/brg_endian.h.orig	2014-04-13 08:40:33.000000000 +0000
+++ packages/clib/sha1/brg_endian.h
@@ -39,7 +39,7 @@
 /* Include files where endian defines and byteswap functions may reside */
 #if defined(__sun__)
 #  include <sys/isa_defs.h>
-#elif defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
+#elif defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ ) || defined( __DragonFly__)
 #  include <sys/endian.h>
 #elif defined( BSD ) && ( BSD >= 199103 ) || defined( __APPLE__ ) || \
       defined( __CYGWIN__ ) || defined( __DJGPP__ ) || defined( __osf__ )
