$NetBSD: patch-config.mk,v 1.1 2020/01/11 16:18:15 nia Exp $

Append instead of setting variables

--- config.mk.orig	2017-04-16 16:28:50.000000000 +0000
+++ config.mk
@@ -13,9 +13,9 @@ INCS = -I${PIXMANINC}
 LIBS = -lwayland-client -lxkbcommon -lwld -lfontconfig
 
 # flags
-CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -DVERSION=\"${VERSION}\"
-CFLAGS   = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS  = -s ${LIBS}
+CPPFLAGS += -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -DVERSION=\"${VERSION}\"
+CFLAGS   += -std=c99 -pedantic -Wall ${INCS} ${CPPFLAGS}
+LDFLAGS  += -s ${LIBS}
 
 # compiler and linker
 CC = cc
