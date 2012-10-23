# $NetBSD: Makefile,v 1.4 2012/10/23 19:50:50 asau Exp $

DISTNAME=		afbinit_1.0.orig
PKGNAME=		afbinit-1.0
CATEGORIES=		sysutils graphics
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/contrib/a/afbinit/}

MAINTAINER=		macallan@NetBSD.org
COMMENT=		Firmware download tool for Sun AFB graphic cards

WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/}
BUILD_TARGET=		afbinit
ONLY_FOR_PLATFORM=	*-*-sparc64 *-*-sparc

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/afbinit ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
