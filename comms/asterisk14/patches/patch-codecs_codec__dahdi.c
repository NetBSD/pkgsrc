$NetBSD: patch-codecs_codec__dahdi.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- codecs/codec_dahdi.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ codecs/codec_dahdi.c
@@ -38,9 +38,9 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 
 #include <fcntl.h>
 #include <netinet/in.h>
+#include <poll.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
-#include <sys/poll.h>
 #include <dahdi/user.h>
 
 #include "asterisk/lock.h"
