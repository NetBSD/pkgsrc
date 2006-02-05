# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:02 joerg Exp $

DISTNAME=		libffm.0.28
PKGNAME=		libffm-0.28
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.unix-ag.org/user/nils/

MAINTAINER=		root@garbled.net
COMMENT=		Fast alpha-optimized replacement for some libm routines

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=      NetBSD-*-alpha

INSTALLATION_DIRS=	lib include

do-install:
	${INSTALL_DATA} ${WRKSRC}/libffm.a ${PREFIX}/lib/libffm.a
	${INSTALL_DATA} ${WRKSRC}/libffm.h ${PREFIX}/include/libffm.h
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libffm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libffm

.include "../../mk/bsd.pkg.mk"
