$NetBSD: patch-Makefile.inc,v 1.1 2012/03/21 19:22:31 hans Exp $

--- Makefile.inc.orig	2012-03-21 20:14:50.782202133 +0100
+++ Makefile.inc	2012-03-21 20:16:37.118104356 +0100
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
