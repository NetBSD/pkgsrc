$NetBSD: patch-codecs_codec__dahdi.c,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- codecs/codec_dahdi.c.orig	2015-10-09 22:23:39.000000000 +0000
+++ codecs/codec_dahdi.c
@@ -37,9 +37,9 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 
 #include <fcntl.h>
 #include <netinet/in.h>
+#include <poll.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
-#include <sys/poll.h>
 #include <dahdi/user.h>
 
 #include "asterisk/lock.h"
