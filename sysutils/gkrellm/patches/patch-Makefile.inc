$NetBSD: patch-Makefile.inc,v 1.2 2013/02/26 16:16:09 jperkin Exp $

Match OPSYS with what pkgsrc uses.
Add an explicit -lm and -lgmodule-2.0 for Solaris.

--- Makefile.inc.orig	2013-02-26 15:55:55.253179839 +0000
+++ Makefile.inc
@@ -66,7 +66,7 @@ endif
 
 ifeq ($(GTOP),)
 # OS-specific overrides
-SUPPORTED_OSES=	Linux NetBSD FreeBSD OpenBSD Darwin Solaris DragonFly
+SUPPORTED_OSES=	Linux NetBSD FreeBSD OpenBSD Darwin SunOS DragonFly
 
 REALOPSYS=	$(shell uname -s)
 OPSYS=		$(if $(findstring $(REALOPSYS),$(SUPPORTED_OSES)),$(REALOPSYS),Linux)
@@ -106,11 +106,11 @@ HAVE_GETADDRINFO=	1
 LINK_FLAGS+=	-lX11
     endif
    else
-    ifeq ($(OPSYS),Solaris)
+    ifeq ($(OPSYS),SunOS)
 MSGFMT_OPT=	-v 
 CC?=		gcc
 GKRELLM_CFLAGS=	-Wno-implicit-int
-SYS_LIBS=	-lkstat -lkvm -ldevinfo
+SYS_LIBS=	-lm -lkstat -lkvm -ldevinfo
      ifeq ($(OSREV),5.8)
 LINK_FLAGS=
 SYS_LIBS+=	-lsocket -lintl
@@ -123,7 +123,7 @@ GKRELLM_CFLAGS=	-DSOLARIS_8
      else
 SYS_LIBS+=	-lsocket
       ifeq ($(MODULE),src)
-SYS_LIBS+=	-lresolv -lX11
+SYS_LIBS+=	-lresolv -lX11 -lgmodule-2.0
       else
 SYS_LIBS+=	-lnsl
       endif
