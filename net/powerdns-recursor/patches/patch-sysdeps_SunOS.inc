$NetBSD: patch-sysdeps_SunOS.inc,v 1.1 2015/06/10 14:22:29 fhajny Exp $

Do not bother with init.d scripts on SunOS.

--- sysdeps/SunOS.inc.orig	2015-04-21 13:02:57.000000000 +0000
+++ sysdeps/SunOS.inc
@@ -3,7 +3,6 @@ ifeq ($(CC),cc)
 endif
 
 LDFLAGS+=-lresolv -lsocket -lnsl -ldl 
-OS_SPECIFIC_INSTALL=mkdir -p $(DESTDIR)/etc/init.d ; cp pdns-recursor.init.d $(DESTDIR)/etc/init.d/pdns-recursor
 
 LUA_LIBS_CONFIG ?= -llua 
 
