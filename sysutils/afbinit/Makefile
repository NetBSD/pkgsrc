# $NetBSD: Makefile,v 1.3 2010/01/27 18:27:24 joerg Exp $

DISTNAME=		afbinit_1.0.orig
PKGNAME=		afbinit-1.0
CATEGORIES=		sysutils graphics
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/contrib/a/afbinit/}

MAINTAINER=		macallan@NetBSD.org
COMMENT=		Firmware download tool for Sun AFB graphic cards

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/}
BUILD_TARGET=		afbinit
ONLY_FOR_PLATFORM=	*-*-sparc64 *-*-sparc

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/afbinit ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
