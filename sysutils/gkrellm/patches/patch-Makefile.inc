$NetBSD: patch-Makefile.inc,v 1.4 2016/09/17 14:28:59 richard Exp $

Match OPSYS with what pkgsrc uses.
Add an explicit -lm and -lgmodule-2.0 for Solaris.
And -lX11, -lm and -lgmodule-2.0 for Linux

--- Makefile.inc.orig	2016-09-17 12:12:43.663376387 +0000
+++ Makefile.inc
@@ -8,8 +8,8 @@ INSTALLDIR?=	$(INSTALLROOT)/bin
 INCLUDEDIR?=	$(INSTALLROOT)/include
 LOCALEDIR?=	$(INSTALLROOT)/share/locale
 PKGCONFIGDIR?=	$(INSTALLROOT)/lib/pkgconfig
-MANDIR?=	$(INSTALLROOT)/man/man1
-SMANDIR?=	$(INSTALLROOT)/man/man1
+MANDIR?=	$(INSTALLROOT)/$(PKGMANDIR)/man1
+SMANDIR?=	$(INSTALLROOT)/$(PKGMANDIR)/man1
 SINSTALLDIR?=	$(INSTALLROOT)/bin
 
 # Ownership and mode options
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
@@ -134,6 +134,12 @@ BINGROUP=	kmem
 NEED_MD5=	no
 MD5_LIBS=	-lmd
 SYS_LIBS=	-lkvm -lkinfo -ldevstat -lX11 -lm -lgmodule-2.0
+      else
+	ifeq (${OPSYS},Linux)
+	  ifeq ($(MODULE),src)
+SYS_LIBS+=	-lX11 -lm -lgmodule-2.0
+	  endif
+	endif
       endif
     endif
    endif
