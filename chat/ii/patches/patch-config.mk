$NetBSD: patch-config.mk,v 1.1 2020/05/16 18:14:20 nia Exp $

Don't override CFLAGS/LDFLAGS

--- config.mk.orig	2018-02-04 13:36:09.000000000 +0000
+++ config.mk
@@ -21,5 +21,5 @@ CC       = cc
 #LDFLAGS = ${LIBS}
 
 # release
-CFLAGS   = -Os ${INCLUDES} -DVERSION=\"${VERSION}\" -std=c99 -D_DEFAULT_SOURCE
-LDFLAGS  = -s ${LIBS}
+CFLAGS  += ${INCLUDES} -DVERSION=\"${VERSION}\" -std=c99 -D_DEFAULT_SOURCE
+LDFLAGS += -s ${LIBS}
