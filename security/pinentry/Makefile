# $NetBSD: Makefile,v 1.2 2004/10/24 08:58:01 shannonjr Exp $
#

DISTNAME=		pinentry-0.7.1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/pinentry/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/pinentry/
COMMENT=		Applications for entering PINs or Passphrases

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

PKG_OPTIONS_VAR=        PKG_OPTIONS.pinentry
PKG_SUPPORTED_OPTIONS=  qt gtk
.include "../../mk/bsd.options.mk"

post-install:
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
.if !empty(PKG_OPTIONS:Mqt)
	${ECHO} "bin/pinentry-qt" >>${PLIST_SRC}
.endif
.if !empty(PKG_OPTIONS:Mgtk)
	${ECHO} "bin/pinentry-gtk" >>${PLIST_SRC}
.endif

BUILDLINK_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mqt)
.include "../../x11/qt3-libs/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
